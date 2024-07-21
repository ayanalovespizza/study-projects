#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief Метод инициализации таблицы для кредита
 */
void MainWindow::init_credit() {
  QTableWidget *tbl = ui->tableWidget;

  tbl->setColumnCount(4);
  QStringList names = {"Month", "Payment", "Already paid", "Left to pay"};
  tbl->setHorizontalHeaderLabels(names);

  QString styleSheet =
      "font-family: TT Firs Neue; font-size: 12pt; color: #0d0d0d; background: "
      "#f2f2f2; border: 1px;";
  ui->tableWidget->setStyleSheet(styleSheet);
}

/**
 * @brief Метод активации подсчета кредита
 */
void MainWindow::calculate_credit() {
  double credit_sum = ui->credit_amount->value();
  int term = ui->term->value();
  double rate = ui->rate->value();

  bool flag_type =
      ui->radioButton_ann->isChecked() || ui->radioButton_dif->isChecked();

  if (credit_sum == 0 || term == 0 || rate == 0 || flag_type == false) {
    QString tooltipText = "Please fill in all fields to calculate credit";
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
    init_credit();
    if (ui->radioButton_ann->isChecked()) {
      calculate_ann(credit_sum, term, rate);
    } else if (ui->radioButton_dif->isChecked()) {
      calculate_dif(credit_sum, term, rate);
    }
  }
}

/**
 * @brief Метод расчета кредита с аннуитентными платежами
 */
void MainWindow::calculate_ann(double credit_sum, double term, double rate) {
  QTableWidget *table = ui->tableWidget;
  table->setRowCount(term);
  table->verticalHeader()->setVisible(false);
  double sum_orig = credit_sum;
  double payment = 0;
  double monthly_payment;
  double monthly_rate = rate / 1200;
  for (int month = 1; month <= term; month++) {
    monthly_payment = credit_sum * monthly_rate /
                      (1 - pow(1 + monthly_rate, -1 * (term - month + 1)));
    monthly_payment = round(monthly_payment * 100) / 100;
    payment += monthly_payment;
    credit_sum = credit_sum * (1 + monthly_rate) - monthly_payment;
    credit_sum = round(credit_sum * 100) / 100;
    table->setItem(month - 1, 0, new QTableWidgetItem(QString::number(month)));
    table->setItem(
        month - 1, 1,
        new QTableWidgetItem(QString::number(monthly_payment, 'f', 2)));
    table->setItem(month - 1, 2,
                   new QTableWidgetItem(QString::number(payment, 'f', 2)));
    table->setItem(month - 1, 3,
                   new QTableWidgetItem(QString::number(credit_sum, 'f', 2)));
  }
  table->resizeColumnsToContents();
  for (int col = 0; col < 4; ++col) {
    int currentWidth = table->columnWidth(col);
    table->setColumnWidth(col, currentWidth + 15);
  }
  ui->result_total_payment->setText(QString::number(payment, 'f', 2));
  ui->result_overpayment->setText(QString::number(payment - sum_orig, 'f', 2));

  for (int column = 0; column < ui->tableWidget->columnCount(); ++column) {
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
      QTableWidgetItem *item = ui->tableWidget->item(row, column);
      if (item)
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
    }
  }
}

/**
 * @brief Метод расчета кредита с дифференцированными платежами
 */
void MainWindow::calculate_dif(double credit_sum, double term, double rate) {
  QTableWidget *table = ui->tableWidget;
  table->setRowCount(term);
  table->verticalHeader()->setVisible(false);
  double sum_orig = credit_sum;
  double payment = 0;
  double monthly_payment;
  double monthly_rate = rate / 1200;
  double main_part = credit_sum / term;
  for (int month = 1; month <= term; month++) {
    monthly_payment = main_part + credit_sum * monthly_rate;
    monthly_payment = round(monthly_payment * 100) / 100;
    payment += monthly_payment;
    credit_sum = credit_sum * (1 + monthly_rate) - monthly_payment;
    credit_sum = round(credit_sum * 100) / 100;
    table->setItem(month - 1, 0, new QTableWidgetItem(QString::number(month)));
    table->setItem(
        month - 1, 1,
        new QTableWidgetItem(QString::number(monthly_payment, 'f', 2)));
    table->setItem(month - 1, 2,
                   new QTableWidgetItem(QString::number(payment, 'f', 2)));
    table->setItem(month - 1, 3,
                   new QTableWidgetItem(QString::number(credit_sum, 'f', 2)));
  }
  table->resizeColumnsToContents();
  for (int col = 0; col < 4; ++col) {
    int currentWidth = table->columnWidth(col);
    table->setColumnWidth(col, currentWidth + 15);
  }
  ui->result_total_payment->setText(QString::number(payment, 'f', 2));
  ui->result_overpayment->setText(QString::number(payment - sum_orig, 'f', 2));

  for (int column = 0; column < ui->tableWidget->columnCount(); ++column) {
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
      QTableWidgetItem *item = ui->tableWidget->item(row, column);
      if (item)
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
    }
  }
}
