#include "graph.h"

#include <QVector>

#include "ui_graph.h"

/**
 * @brief Метод инициализации графа и клавиш
 */
Graph::Graph(QWidget *parent) : QDialog(parent), ui(new Ui::graph) {
  ui->setupUi(this);
  connect(ui->pushButton_build, SIGNAL(clicked()), this, SLOT(build()));
  connect(ui->pushButton_close, SIGNAL(clicked()), this, SLOT(close_window()));
}

Graph::~Graph() { delete ui; }

/**
 * @brief Метод построения графика
 */
void Graph::build() {
  QString expression = m_expression;

  xMax = ui->doubleSpinBox_xmax->value();
  xMin = ui->doubleSpinBox_xmin->value();
  yMax = ui->doubleSpinBox_ymax->value();
  yMin = ui->doubleSpinBox_ymin->value();

  step = 0.001;
  xBegin = xMin;
  xEnd = xMax;

  ui->widget->xAxis->setRange(xMin, xMax);
  ui->widget->yAxis->setRange(yMin, yMax);

  N = (xEnd - xBegin) / step + 2;
  for (X = xBegin; X <= xEnd; X += step) {
    double Y_tmp = solveExpression(expression, X);
    x.push_back(X);
    y.push_back(Y_tmp);
  }

  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}

/**
 * @brief Метод закрытия окна для построения графиков
 */
void Graph::close_window() { QDialog::close(); }

/**
 * @brief Метод установки значения для закрытого поля с выражением
 */
void Graph::setExpression(const QString &expression) {
  m_expression = expression;
}

/**
 * @brief Метод расчета значения функции при определенном X
 */
double Graph::solveExpression(QString expression, double X) {
  expression.replace("√", "v");
  expression.replace("×", "*");
  expression.replace("÷", "/");

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
  expression.replace("x", QString("(%1)").arg(X));

  QByteArray expression_utf8 = expression.toUtf8();
  lexem_list *polish_notation = ToPolish(expression_utf8.data());
  char *result = SolvePolish(polish_notation);
  QString result_str = QString::fromUtf8(result);
  return result_str.toDouble();
}
