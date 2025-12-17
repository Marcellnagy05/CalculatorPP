#include "CalculatorPP.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>

CalculatorPP::CalculatorPP(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculatorPPClass())
    , firstNumber(0.0)
    , waitingForSecondNumber(false)
{
    ui->setupUi(this);

    // Display mező beállítása
    ui->display->setReadOnly(true);
    ui->display->setText("0");

    // Gombok összekötése
    setupConnections();
}

CalculatorPP::~CalculatorPP()
{
    delete ui;
}

void CalculatorPP::setupConnections()
{
    // Szám gombok (0-9)
    for (int i = 0; i <= 9; ++i) {
        QString buttonName = QString("btn%1").arg(i);
        QPushButton* button = findChild<QPushButton*>(buttonName);

        if (button) {
            connect(button, &QPushButton::clicked, this, &CalculatorPP::onNumberClicked);
        }
    }

    // Művelet gombok
    QStringList operations = { "btnPlus", "btnSubtraction", "btnMultiply", "btnDivide" };
    foreach(const QString & opName, operations) {
        QPushButton* button = findChild<QPushButton*>(opName);
        if (button) {
            connect(button, &QPushButton::clicked, this, &CalculatorPP::onOperationClicked);
        }
    }

    // Egyenlő gomb
    QPushButton* equalsBtn = findChild<QPushButton*>("btnEquals");
    if (equalsBtn) {
        connect(equalsBtn, &QPushButton::clicked, this, &CalculatorPP::onEqualsClicked);
    }

    // Törlés gomb
    QPushButton* resetBtn = findChild<QPushButton*>("btnReset");
    if (resetBtn) {
        connect(resetBtn, &QPushButton::clicked, [this]() {
            resetCalculator();
            ui->display->setText("0");
            });
    }
}

void CalculatorPP::onNumberClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton) return;

    QString digit = clickedButton->text();
    QString currentText = ui->display->text();

    if (currentText == "0" || waitingForSecondNumber) {
        currentText = digit;
        waitingForSecondNumber = false;
    }
    else {
        currentText += digit;
    }

    ui->display->setText(currentText);
}

void CalculatorPP::onOperationClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton) return;

    // Az előző szám elmentése
    firstNumber = ui->display->text().toDouble();

    // Művelet mentése
    pendingOperation = clickedButton->text();

    // Készüljünk a következő számra
    waitingForSecondNumber = true;
}

void CalculatorPP::onEqualsClicked()
{
    if (pendingOperation.isEmpty()) return;

    double secondNumber = ui->display->text().toDouble();
    double result = 0.0;

    // SimpleMath library használata!
    try {
        if (pendingOperation == "+") {
            result = mathEngine.add(firstNumber, secondNumber);
        }
        else if (pendingOperation == "-") {
            result = mathEngine.sub(firstNumber, secondNumber);
        }
        else if (pendingOperation == "×" || pendingOperation == "*") {
            result = mathEngine.mult(firstNumber, secondNumber);
        }
        else if (pendingOperation == "÷" || pendingOperation == "/") {
            if (secondNumber == 0.0) {
                QMessageBox::warning(this, "Hiba", "Nullával nem lehet osztani!");
                return;
            }
            result = mathEngine.div(firstNumber, secondNumber);
        }

        // Eredmény megjelenítése
        updateDisplay(result);

    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Hiba", QString("Számítási hiba: %1").arg(e.what()));
    }

    // Reset
    pendingOperation.clear();
    waitingForSecondNumber = true;
}

void CalculatorPP::updateDisplay(double value)
{
    // Formázás: ha egész szám, ne legyen tizedes
    if (value == std::floor(value)) {
        ui->display->setText(QString::number(static_cast<long long>(value)));
    }
    else {
        ui->display->setText(QString::number(value, 'f', 6));
    }
}

void CalculatorPP::resetCalculator()
{
    firstNumber = 0.0;
    pendingOperation.clear();
    waitingForSecondNumber = false;
}