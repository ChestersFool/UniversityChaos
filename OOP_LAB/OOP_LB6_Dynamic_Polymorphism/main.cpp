#include <iostream>
#include <cmath>

using namespace std;

struct Function
{
private:
public:
    double _XCoef, _Constant;

    Function(double xCoef, double constant)
    {
        this->_XCoef = xCoef;
        this->_Constant = constant;
    }

    void Output()
    {
        cout << "xCoef - " << this->_XCoef << " constant - " << this->_Constant << endl;
    }

    void Input()
    {
        cout << "Enter x and constant: ";
        cin >> this->_XCoef, this->_Constant;
    }

    double f(double currentX)
    {
        return sin(this->_XCoef * currentX) + this->_Constant;
    }
};

class NumericalIntegration
{
protected:
    double _A, _B;
    Function *_PFunction;

public:
    NumericalIntegration() = default;
    NumericalIntegration(double a, double b, Function *PFunction)
    {
        cout << "Constructor BASE\n";
        this->_A = a;
        this->_B = b;
        this->_PFunction = new Function(PFunction->_XCoef, PFunction->_Constant);
    }

    virtual ~NumericalIntegration() = 0;

    virtual void Print()
    {
        cout << "Limits: upper - " << this->_B << " lower - " << this->_A << endl
             << "Function: ";
        _PFunction->Output();
    }
    void Input()
    {
        cout << "Enter upper and lower bound: ";
        cin >> this->_A, this->_B;
        _PFunction->Input();
    }
    void Init(double a, double b, Function *PFunction)
    {
        this->_A = a;
        this->_B = b;
        delete _PFunction;
        this->_PFunction = new Function(PFunction->_XCoef, PFunction->_Constant);
    }

    virtual double Calculate() = 0;
};

NumericalIntegration::~NumericalIntegration()
{
    cout << "\nBASE";
    delete _PFunction;
}

class RectangleMethod : public NumericalIntegration
{
public:
    RectangleMethod() = default;
    RectangleMethod(double a, double b, Function *PFunction) : NumericalIntegration(a, b, PFunction)
    {
        cout << "Constructor RectangleMethod\n";
    }

    virtual ~RectangleMethod()
    {
        cout << "\nRectangleMethod";
    }

    virtual void Print() override
    {
        cout << "!!!RectangleMethod!!!\n";
        ::NumericalIntegration::Print();
        cout << "a.Calculate() - " << this->Calculate() << "\n\n";
    }

    virtual double Calculate() override
    {
        double h = fabs(this->_B - this->_A) / 100;
        double sum = 0, currentX;

        for (int i = 1; i <= 100; i++)
        {
            currentX = this->_A + i * h;
            sum += _PFunction->f(currentX);
        }

        return sum *= h;
    }
};

class SimpsonMethod : public NumericalIntegration
{
public:
    SimpsonMethod() = default;
    SimpsonMethod(double a, double b, Function *PFunction) : NumericalIntegration(a, b, PFunction)
    {
        cout << "Constructor SimpsonMethod\n";
    }

    virtual ~SimpsonMethod()
    {
        cout << "\nSimpsonMethod";
    }

    virtual void Print() override
    {
        cout << "!!!SimpsonMethod!!!\n";
        ::NumericalIntegration::Print();
        cout << "a.Calculate() - " << this->Calculate() << "\n\n";
    }

    virtual double Calculate() override
    {
        double h = fabs(this->_B - this->_A) / 100;
        double sum1 = 0, sum2 = 0, currentX;

        for (int i = 1; i < 100; i += 2)
        {
            sum1 += _PFunction->f(this->_A + i * h);
            sum2 += _PFunction->f(this->_A + (i + 1) * h);
        }

        return h / 3 * ((sin(_PFunction->_XCoef * this->_A) + _PFunction->_Constant) + 4 * sum1 + 2 * sum2);
    }
};

void printAll(NumericalIntegration *mas[], int start, int end)
{
    for (int i = start; i < end; i++)
        mas[i]->Print();
}

void diffBetweenRectangleMethodAndSimpsonMethod(NumericalIntegration *mas[], int start, int end)
{
    for (int i = start; i < end; i += 2)
        cout << i + 1 << ". The difference between the RectangleMethod and the SimpsonMethod - " << fabs(mas[i]->Calculate() - mas[i + 1]->Calculate()) << endl;
}

// TODO ЗДАТИ!!!!!
// FIXME ВСЕ ОК!!!
int main()
{
    Function *pFirst = new Function(1, 2);
    RectangleMethod a(0, 10, pFirst), b(2, 4, pFirst), c(-2, 10, pFirst);
    SimpsonMethod A(0, 10, pFirst), B(2, 4, pFirst), C(-2, 10, pFirst);
    NumericalIntegration *mas[10] = {&a, &A, &b, &B, &c, &C};

    cout << endl;
    printAll(mas, 0, 6);
    diffBetweenRectangleMethodAndSimpsonMethod(mas, 0, 5);

    // delete mas[3];
    return 0;
}
