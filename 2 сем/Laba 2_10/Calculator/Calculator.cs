using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace Calculator
{
    public class CalculatorEngine
    {
        private double currentValue;
        private double memory;
        private char operation;
        private double firstOperand;
        private bool isOperationPerformed;

        public double CurrentValue
        {
            get { return currentValue; }
            set { currentValue = value; }
        }

        public double Memory
        {
            get { return memory; }
            set { memory = value; }
        }

        public char Operator
        {
            get { return operation; }
            set { operation = value; }
        }

        public void AddDigitToDisplay(int digit)
        {
            if (isOperationPerformed)
            {
                currentValue = 0;
                isOperationPerformed = false;
            }

            currentValue = currentValue * 10 + digit;
        }

        public void SetOperator(char op)
        {
            if (isOperationPerformed)
            {
                firstOperand = currentValue;
            }
            else
            {
                firstOperand = currentValue;
                currentValue = 0;
            }

            operation = op;
            isOperationPerformed = true;
        }

        // Выполняет вычисление с использованием сохраненного значения, текущего значения и выбранной операции
        public void CalculateResult()
        {
            double secondOperand = currentValue;
            double result = 0;

            switch (operation)
            {
                case '+':
                    result = firstOperand + secondOperand;
                    break;
                case '-':
                    result = firstOperand - secondOperand;
                    break;
                case 'x':
                    result = firstOperand * secondOperand;
                    break;
                case '/':
                    if (secondOperand != 0)
                    {
                        result = firstOperand / secondOperand;
                    }
                    else
                    {
                        // Обработка деления на ноль
                        CurrentValue = 0;
                        return;
                    }
                    break;
                default:
                    // Обработка неизвестной операции
                    CurrentValue = 0;
                    return;
            }

            CurrentValue = result;
            isOperationPerformed = true;
        }

        // Сбрасывает все значения калькулятора
        public void ClearAll()
        {
            currentValue = 0;
            memory = 0;
            operation = '\0';
            isOperationPerformed = false;
        }

        // Очищает текущее значение на дисплее.
        public void ClearEntry()
        {
            currentValue = 0;
        }

        // Кнопка "←" (удаление последнего символа)
        public void RemoveLastDigit()
        {
            if (currentValue != 0)
            {
                currentValue = Math.Floor(currentValue / 10);
            }
        }

        public void Power()
        {
            currentValue = Math.Pow(firstOperand, currentValue);
            isOperationPerformed = true;
        }

        public void ChangeSign()
        {
            currentValue = -currentValue;
        }

        public void CalculateSquareRoot()
        {
            if (currentValue >= 0)
            {
                currentValue = Math.Sqrt(currentValue);
            }
        }

        // Метод для преобразования входного выражения в обратную польскую запись
        public Queue<string> ConvertToReversePolishNotation(string inputExpression)
        {
            Queue<string> output = new Queue<string>();
            Stack<char> operators = new Stack<char>();

            foreach (char token in inputExpression)
            {
                if (char.IsDigit(token))
                {
                    // Если символ является числом, добавляем его в выходную очередь
                    output.Enqueue(token.ToString());
                }
                else if (token == '(')
                {
                    // Если символ - открывающая скобка, помещаем его в стек операторов
                    operators.Push(token);
                }
                else if (token == ')')
                {
                    // Если символ - закрывающая скобка, извлекаем операторы из стека
                    // и добавляем их в выходную очередь до тех пор, пока не встретим открывающую скобку
                    while (operators.Count > 0 && operators.Peek() != '(')
                    {
                        output.Enqueue(operators.Pop().ToString());
                    }
                    operators.Pop(); // Удаляем открывающую скобку из стека
                }
                else
                {
                    // Если символ - оператор, извлекаем операторы из стека, которые имеют
                    // более высокий или равный приоритет, и добавляем их в выходную очередь
                    while (operators.Count > 0 && Precedence(operators.Peek()) >= Precedence(token))
                    {
                        output.Enqueue(operators.Pop().ToString());
                    }
                    operators.Push(token); // Добавляем текущий оператор в стек
                }
            }

            // Добавляем оставшиеся операторы из стека в выходную очередь
            while (operators.Count > 0)
            {
                output.Enqueue(operators.Pop().ToString());
            }

            return output;
        }

        // Вспомогательный метод для определения приоритета оператора
        private int Precedence(char op)
        {
            switch (op)
            {
                case '+':
                case '-':
                    return 1;
                case '*':
                case '/':
                    return 2;
                case '^':
                    return 3;
                default:
                    return 0;
            }
        }

        public double CalculateFromReversePolishNotation(Queue<string> reversePolishNotation)
        {
            Stack<double> operands = new Stack<double>();

            while (reversePolishNotation.Count > 0)
            {
                string token = reversePolishNotation.Dequeue();

                if (double.TryParse(token, out double operand))
                {
                    // Если токен является числом, помещаем его в стек операндов
                    operands.Push(operand);
                }
                else
                {
                    // Если токен является оператором, извлекаем два операнда из стека
                    double operand2 = operands.Pop();
                    double operand1 = operands.Pop();

                    // Выполняем операцию и помещаем результат обратно в стек операндов
                    switch (token)
                    {
                        case "+":
                            operands.Push(operand1 + operand2);
                            break;
                        case "-":
                            operands.Push(operand1 - operand2);
                            break;
                        case "*":
                            operands.Push(operand1 * operand2);
                            break;
                        case "/":
                            operands.Push(operand1 / operand2);
                            break;
                        case "^":
                            operands.Push(Math.Pow(operand1, operand2));
                            break;
                    }
                }
            }

            // Возвращаем результат из стека операндов
            return operands.Pop();
        }

    }
}

