#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFont>
#include <QInputDialog>
#include <QMainWindow>
#include <QTableWidget>
#include <QTimer>
#include <QToolTip>

#ifdef __cplusplus
extern "C" {
#endif

#include "../calculate/headers/helpers.h"
#include "../calculate/headers/polish.h"
#include "../calculate/headers/validators.h"

#ifdef __cplusplus
}
#endif

#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void init_credit();
  void calculate_ann(double credit_sum, double term, double rate);
  void calculate_dif(double credit_sum, double term, double rate);

  void calculateDeposit_withCapital(double deposit, int deposit_term,
                                    double int_rate, double tax_rate,
                                    int periodicity);
  void calculateDeposit_noCapital(double deposit, int deposit_term,
                                  double int_rate, double tax_rate,
                                  int periodicity);

private:
  Ui::MainWindow *ui;
  Graph graph;

private slots:
  void digits_numbers();
  void functions();
  void on_pushButton_full_del_clicked();
  void on_pushButton_del_clicked();
  void operations();
  //  void on_pushButton_equal_clicked();
  void on_pushButton_set_x_clicked();
  void build_graph();
  void test_result();

  void calculate_credit();

  void add_replenishment();
  void add_withdraw();
  void clear_table();
  void calculate_deposit();
};
#endif // MAINWINDOW_H
