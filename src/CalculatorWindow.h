#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QLineEdit>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QTabWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QPoint>

class CalculatorWindow : public QMainWindow {
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

public:
    explicit CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

private slots:
    // Math slots
    void onMathButtonClicked();
    void onMathCalculate();
    void onMathClear();

    // Temperature slots
    void onTempConvert();

    // Number Conversion slots
    void onNumConvert();
    void onMathBackspace();

    // Currency slots
    void onCurrencyConvert();
    void onCurrencyFetchRates();
    void onCurrencyNetworkReply(QNetworkReply* reply);

private:
    void setupUi();
    void processMathInput(const QString &text);
    
    QPoint dragPosition;
    QTabWidget *tabWidget;
    
    // Math UI
    QLabel *mathHistory;
    QLineEdit *mathDisplay;
    double currentMathValue;
    QString pendingMathOp;
    bool waitingForNewOperand;
    bool isUpdatingBoxes;
    int prevTempFromIdx;
    int prevTempToIdx;
    int prevNumFromIdx;
    int prevNumToIdx;
    int prevCurrFromIdx;
    int prevCurrToIdx;

    // Temperature UI
    QDoubleSpinBox *tempInput;
    QComboBox *tempFrom;
    QComboBox *tempTo;
    QLabel *tempResult;

    // Number Conversion UI
    QLineEdit *numInput;
    QComboBox *numFrom;
    QComboBox *numTo;
    QLabel *numResult;

    // Currency UI
    QDoubleSpinBox *currencyInput;
    QComboBox *currencyFrom;
    QComboBox *currencyTo;
    QLabel *currencyResult;
    QLabel *currencyStatus;
    QNetworkAccessManager *networkManager;
    double usdToIdrRate; // We store 1 USD = X IDR
};

#endif // CALCULATORWINDOW_H
