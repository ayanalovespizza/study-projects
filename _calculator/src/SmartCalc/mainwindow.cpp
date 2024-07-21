#include "mainwindow.h"

#include <QDebug>

#include "ui_mainwindow.h"

/**
 * @brief Метод инициализации главного окна
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  /* Блок сигналов от кнопок */
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));

  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(functions()));

  connect(ui->pushButton_open_br, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_close_br, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));

  connect(ui->pushButton_full_del, SIGNAL(clicked()), this,
          SLOT(on_pushButton_full_del_clicked()));
  connect(ui->pushButton_full_del, SIGNAL(clicked()), this,
          SLOT(on_pushButton_del_clicked()));

  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_min, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(operations()));

  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(test_result()));
  connect(ui->pushButton_set_x, SIGNAL(clicked()), this,
          SLOT(on_pushButton_set_x_clicked()));
  connect(ui->pushButton_build, SIGNAL(clicked()), this, SLOT(build_graph()));

  connect(ui->pushButton_calculate, SIGNAL(clicked()), this,
          SLOT(calculate_credit()));

  connect(ui->pushButton_replenishment, SIGNAL(clicked()), this,
          SLOT(add_replenishment()));
  connect(ui->pushButton_withdraw, SIGNAL(clicked()), this,
          SLOT(add_withdraw()));
  connect(ui->pushButton_cleartable, SIGNAL(clicked()), this,
          SLOT(clear_table()));
  connect(ui->pushButton_calcdeposit, SIGNAL(clicked()), this,
          SLOT(calculate_deposit()));
}

/**
 * @brief Деструктор для главного окна
 */
MainWindow::~MainWindow() { delete ui; }

/**
 * @brief Метод для ввода цифр
 */
void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString new_str = (ui->result_show->text() + button->text());
  ui->result_show->setText(new_str);
}

/**
 * @brief Метод для ввода функций
 */
void MainWindow::functions() {
  QPushButton *button = (QPushButton *)sender();
  QString new_str;
  new_str = ui->result_show->text() + button->text() + "(";
  ui->result_show->setText(new_str);
}

/**
 * @brief Метод для полного удаления ввода
 */
void MainWindow::on_pushButton_full_del_clicked() {
  ui->result_show->setText("");
}

/**
 * @brief Метод для удаления последнего символа ввода
 */
void MainWindow::on_pushButton_del_clicked() {
  QString text = ui->result_show->text();

  if (!text.isEmpty()) {
    text.chop(1);
    ui->result_show->setText(text);
  }
}

/**
 * @brief Метод для ввода операторов
 */
void MainWindow::operations() {
  QPushButton *button = (QPushButton *)sender();
  QString new_str;
  new_str = ui->result_show->text();

  if (button->text() == "÷" && !(ui->result_show->text().endsWith("÷"))) {
    new_str += "÷";
  } else if (button->text() == "×" &&
             !(ui->result_show->text().endsWith("×"))) {
    new_str += "×";
  } else if (button->text() == "+" &&
             !(ui->result_show->text().endsWith("+"))) {
    new_str += "+";
  } else if (button->text() == "-" &&
             !(ui->result_show->text().endsWith("-"))) {
    new_str += "-";
  } else if (button->text() == "^" &&
             !(ui->result_show->text().endsWith("^"))) {
    new_str += "^";
  } else if (button->text() == "√" &&
             !(ui->result_show->text().endsWith("√"))) {
    new_str += "√(";
  } else if (button->text() == "%" &&
             !(ui->result_show->text().endsWith("%"))) {
    new_str += "%";
  } else if (button->text() == "." &&
             !(ui->result_show->text().endsWith("."))) {
    new_str += ".";
  }

  ui->result_show->setText(new_str);
}

/**
 * @brief Метод для ввода пользовательского значения "x"
 */
void MainWindow::on_pushButton_set_x_clicked() {
  QInputDialog dialog(this);
  dialog.setWindowTitle("Enter X value");
  dialog.setLabelText("X value:");
  dialog.setInputMode(QInputDialog::DoubleInput);
  dialog.setDoubleMinimum(-1000.0);
  dialog.setDoubleMaximum(1000.0);
  dialog.setDoubleDecimals(10);
  dialog.setStyleSheet(
      "QInputDialog { background-color: #E0D8F2; font-family: 'TT Firs Neue'; "
      "font-size: 14px;}"
      "QLabel { color: #0D0D0D; font-family: 'TT Firs Neue'; font-size: 14px; }"
      "QLineEdit { color: #0D0D0D; font-family: 'TT Firs Neue'; font-size: "
      "14px; }"
      "QPushButton { background-color: #726881; color: #F2F2F2; border-radius: "
      "5px; padding: 5px 10px; font-family: 'TT Firs Neue'; font-size: 14px; }"
      "QPushButton:hover { background-color: #726881; color: #F2F2F2; "
      "font-family: 'TT Firs Neue'; font-size: 14px; }");

  if (dialog.exec() == QDialog::Accepted) {
    double x_value = dialog.doubleValue();
    QString expression = ui->result_show->text();

    for (int i = 0; i < expression.length(); i++) {
      if (expression[i] == 'x') {
        if (i > 0 && expression[i - 1].isDigit()) {
          expression.insert(i, "×");
          i++;
        }
        if (i < expression.length() - 1 && expression[i + 1].isDigit()) {
          expression.insert(i + 1, "×");
          i++;
        }
      }
    }
    expression.replace("x", QString::number(x_value));
    ui->result_show->setText(expression);
  }
}

/**
 * @brief Метод для нажатия кнопки построения графика
 */
void MainWindow::build_graph() {
  QString expression = ui->result_show->text();
  Graph graph(this);
  graph.setExpression(expression);
  graph.exec();
}

/**
 * @brief Метод для нажатия кнопки "равно"
 */
void MainWindow::test_result() {
  QString expression = ui->result_show->text();
  expression.replace("√", "v");
  expression.replace("×", "*");
  expression.replace("÷", "/");

  QByteArray expression_utf8 = expression.toUtf8();

  if (expression.contains('x')) {
    QString tooltipText = "Please replace x with 'set x'";
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
    if (InsertionIsValid((char *)expression_utf8.data()) == 1) {
      lexem_list *polish_notation = ToPolish((char *)expression_utf8.data());
      char *result = SolvePolish(polish_notation);
      QString result_str = QString::fromUtf8(result);
      ui->result_show->setText(result_str);

    } else {
      ui->result_show->setStyleSheet(
          "QLabel {qproperty-alignment: 'AlignVCenter | AlignRight'; "
          "background-color: #F2F2F2; border-radius: 10px; color: #0D0D0D; "
          "padding: 10px; border-style: solid; border-width: 2px; "
          "border-color: #A67C7C;}");
      ui->result_show->setText("Error!!!");
      QTimer::singleShot(1500, this, [this]() {
        ui->result_show->clear();
        ui->result_show->setStyleSheet(
            "QLabel {qproperty-alignment: 'AlignVCenter | AlignRight'; "
            "background-color: #F2F2F2; border-radius: 10px;color: #0D0D0D; "
            "padding: 10px;}");
      });
    }
  }
}
