#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief Метод добавления суммы в депозит
 */
void MainWindow::add_replenishment() {
  double amount = ui->doubleSpinBox_add_amount->value();
  int month = ui->doubleSpinBox_add_month->value();

  if (amount == 0 || month == 0) {
    QString tooltipText = "Please fill in all fields to make a replenishment";
    QColor backgroundColor(242, 242, 242);
    QColor textColor(166, 124, 124);

    QPalette palette;
    palette.setColor(QPalette::ToolTipBase, backgroundColor);
    palette.setColor(QPalette::ToolTipText, textColor);

    QToolTip::setPalette(palette);
    QToolTip::setFont(QFont("TT Firs Neue", 18));

    QToolTip::showText(ui->result_show->mapToGlobal(QPoint(0, -15)),
                       tooltipText);
    QTimer::singleShot(2000, QToolTip::hideText);
  } else {
    int rowCount = ui->tableDeposit->rowCount();
    ui->tableDeposit->insertRow(rowCount);

    ui->tableDeposit->setItem(rowCount, 0,
                              new QTableWidgetItem(QString::number(month)));
    ui->tableDeposit->setItem(rowCount, 1,
                              new QTableWidgetItem("Replenishment"));
    ui->tableDeposit->setItem(
        rowCount, 2, new QTableWidgetItem(QString::number(amount, 'f', 2)));
  }
}

/**
 * @brief Метод снятия суммы с депозита
 */
void MainWindow::add_withdraw() {
  double amount = ui->doubleSpinBox_min_amount->value();
  int month = ui->doubleSpinBox_min_month->value();

  if (amount == 0 || month == 0) {
    QString tooltipText = "Please fill in all fields to withdraw money";
    QColor backgroundColor(242, 242, 242);
    QColor textColor(166, 124, 124);

    QPalette palette;
    palette.setColor(QPalette::ToolTipBase, backgroundColor);
    palette.setColor(QPalette::ToolTipText, textColor);

    QToolTip::setPalette(palette);
    QToolTip::setFont(QFont("TT Firs Neue", 18));

    QToolTip::showText(ui->result_show->mapToGlobal(QPoint(0, -15)),
                       tooltipText);
    QTimer::singleShot(2000, QToolTip::hideText);
  } else {
    int rowCount = ui->tableDeposit->rowCount();
    ui->tableDeposit->insertRow(rowCount);

    ui->tableDeposit->setItem(rowCount, 0,
                              new QTableWidgetItem(QString::number(month)));
    ui->tableDeposit->setItem(rowCount, 1, new QTableWidgetItem("Withdraw"));
    ui->tableDeposit->setItem(
        rowCount, 2, new QTableWidgetItem(QString::number(amount, 'f', 2)));
  }
}

/**
 * @brief Метод очистки таблицы снятий и пополнений депозита
 */
void MainWindow::clear_table() {
  int rowCount = ui->tableDeposit->rowCount();
  for (int row = rowCount - 1; row >= 0; --row) {
    ui->tableDeposit->removeRow(row);
  }
}

/**
 * @brief Метод активации подсчета депозита
 */
void MainWindow::calculate_deposit() {
  double deposit = ui->doubleSpinBox_deposit_amount->value();
  int deposit_term = ui->doubleSpinBox_deposit_term->value();
  double int_rate = ui->doubleSpinBox_int_rate->value();
  double tax_rate = ui->doubleSpinBox_tax_rate->value();
  int periodicity = ui->doubleSpinBox_periodicity->value();

  bool capitalization = ui->radioButton_capital->isChecked();

  if (deposit == 0 || deposit_term == 0 || int_rate == 0 || tax_rate == 0 ||
      periodicity == 0) {
    QString tooltipText = "Please fill in all fields to calculate deposit";
    QColor backgroundColor(242, 242, 242);
    QColor textColor(166, 124, 124);

    QPalette palette;
    palette.setColor(QPalette::ToolTipBase, backgroundColor);
    palette.setColor(QPalette::ToolTipText, textColor);

    QToolTip::setPalette(palette);
    QToolTip::setFont(QFont("TT Firs Neue", 18));

    QToolTip::showText(ui->result_show->mapToGlobal(QPoint(0, -15)),
                       tooltipText);
    QTimer::singleShot(2000, QToolTip::hideText);
  } else {
    if (capitalization) {
      calculateDeposit_noCapital(deposit, deposit_term, int_rate, tax_rate,
                                 periodicity);
    } else {
      calculateDeposit_withCapital(deposit, deposit_term, int_rate, tax_rate,
                                   periodicity);
    }
  }
}

/**
 * @brief Метод подсчета депозита с капитализацией
 */
void MainWindow::calculateDeposit_withCapital(double deposit, int deposit_term,
                                              double int_rate, double tax_rate,
                                              int periodicity) {
  double orig_deposit = deposit;
  double taxes = 0.0;
  double all_taxes = 0.0;
  double sum_rep = 0.0;

  for (int month = 1; month <= deposit_term; month += periodicity) {
    deposit += deposit * (int_rate / 100);
    taxes = deposit * (tax_rate / 100);
    all_taxes += taxes;
    deposit -= taxes;

    for (int row = 0; row < ui->tableDeposit->rowCount(); row++) {
      int month_in_table = ui->tableDeposit->item(row, 0)->text().toInt();
      QString operation = ui->tableDeposit->item(row, 1)->text();
      double amount = ui->tableDeposit->item(row, 2)->text().toDouble();

      if (month_in_table == month) {
        if (operation == "Replenishment") {
          deposit += amount;
          sum_rep -= amount;
        } else if (operation == "Withdraw") {
          deposit -= amount;
          sum_rep += amount;
        }
      }
    }
  }
  ui->result_total_deposit->setText(QString::number(deposit, 'f', 2));
  ui->result_accrued_per->setText(
      QString::number(deposit - orig_deposit - sum_rep, 'f', 2));
  ui->result_total_tax_amount->setText(QString::number(all_taxes, 'f', 2));
}

/**
 * @brief Метод подсчета депозита без капитализации
 */
void MainWindow::calculateDeposit_noCapital(double deposit, int deposit_term,
                                            double int_rate, double tax_rate,
                                            int periodicity) {
  double orig_deposit = deposit;
  double taxes = 0.0;
  double all_taxes = 0.0;
  double sum_rep = 0.0;

  for (int month = 1; month <= deposit_term; month += periodicity) {
    // Начисляем проценты на текущий месяц
    double interest = deposit * (int_rate / 100.0);

    // Вычисляем налог на проценты
    taxes = interest * (tax_rate / 100.0);
    all_taxes += taxes;

    // Учитываем налог в общем депозите
    deposit += interest - taxes;

    // Проверяем таблицу на наличие операций в текущем месяце
    for (int row = 0; row < ui->tableDeposit->rowCount(); row++) {
      int month_in_table = ui->tableDeposit->item(row, 0)->text().toInt();
      QString operation = ui->tableDeposit->item(row, 1)->text();
      double amount = ui->tableDeposit->item(row, 2)->text().toDouble();

      if (month_in_table == month) {
        if (operation == "Replenishment") {
          deposit += amount;
          sum_rep -= amount;
        } else if (operation == "Withdraw") {
          deposit -= amount;
          sum_rep += amount;
        }
      }
    }
  }

  // Выводим результаты расчета
  ui->result_total_deposit->setText(QString::number(deposit, 'f', 2));
  ui->result_accrued_per->setText(
      QString::number(deposit - orig_deposit - sum_rep, 'f', 2));
  ui->result_total_tax_amount->setText(QString::number(all_taxes, 'f', 2));
}
