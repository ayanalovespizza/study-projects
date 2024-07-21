#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QVector>
#include <cmath>

#include "qcustomplot.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "../calculate/headers/helpers.h"
#include "../calculate/headers/polish.h"
#include "../calculate/headers/validators.h"

#ifdef __cplusplus
}
#endif

namespace Ui {
class graph;
}

class Graph : public QDialog {
  Q_OBJECT

public:
  explicit Graph(QWidget *parent = nullptr);
  ~Graph();
  void setExpression(const QString &expression);
  double solveExpression(QString expression, double X);

private:
  Ui::graph *ui;
  QString m_expression;
  double xMax, xMin, yMax, yMin;
  double xBegin, xEnd;
  double step;
  double X; // временная переменная
  int N;    // количество точек
  QVector<double> x, y;

private slots:
  void build();
  void close_window();
};

#endif // GRAPH_H
