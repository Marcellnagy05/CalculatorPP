#pragma once
#ifndef CALCULATORPP_H
#define CALCULATORPP_H

#include <QMainWindow>
#include "SimpleMath.h"
#include <QtWidgets/QMainWindow>
#include "ui_CalculatorPP.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorPPClass; };
QT_END_NAMESPACE

class CalculatorPP : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorPP(QWidget *parent = nullptr);
    ~CalculatorPP();

private slots:
    void onNumberClicked();
    void onEqualsClicked();
    void onOperationClicked();

private:
    Ui::CalculatorPPClass *ui;
    SimpleMath::Calculator mathEngine;
    void setupConnections();
    double firstNumber;
    QString pendingOperation;
    bool waitingForSecondNumber;

    void resetCalculator();
    void updateDisplay(double value);
};
#endif // !CalculatorPP_H

