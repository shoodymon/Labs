using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Calculator
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private CalculatorEngine calculatorEngine;
        private bool isOpenParenthesis = false;

        public MainWindow()
        {
            InitializeComponent();
            calculatorEngine = new CalculatorEngine();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Button button = (Button)sender;
            string buttonContent = button.Content.ToString();

            switch (buttonContent)
            {
                case "0":
                case "1":
                case "2":
                case "3":
                case "4":
                case "5":
                case "6":
                case "7":
                case "8":
                case "9":
                    calculatorEngine.AddDigitToDisplay(int.Parse(buttonContent));
                    txtDisplay.Text = calculatorEngine.CurrentValue.ToString();
                    break;
                case "+":
                case "-":
                case "x":
                case "/":
                    calculatorEngine.SetOperator(char.Parse(buttonContent));
                    break;
                case "=":
                    if (txtDisplay.Text.Contains("(") || txtDisplay.Text.Contains(")"))
                    {
                        // Вычислить результат с учетом скобок
                        Queue<string> expression = calculatorEngine.ConvertToReversePolishNotation(txtDisplay.Text);
                        double result = calculatorEngine.CalculateFromReversePolishNotation(expression);
                        txtDisplay.Text = result.ToString();
                    }
                    else
                    {
                        // Вычислить результат обычных операций
                        calculatorEngine.CalculateResult();
                        txtDisplay.Text = calculatorEngine.CurrentValue.ToString();
                    }
                    break;
                case "C":
                    calculatorEngine.ClearAll();
                    txtDisplay.Text = "0";
                    break;
                case "CE":
                    calculatorEngine.ClearEntry();
                    txtDisplay.Text = "0";
                    break;
                case "←":
                    calculatorEngine.RemoveLastDigit();
                    txtDisplay.Text = calculatorEngine.CurrentValue.ToString();
                    break;
                case "^":
                    calculatorEngine.Power();
                    txtDisplay.Text = calculatorEngine.CurrentValue.ToString();
                    break;
                case "√":
                    calculatorEngine.CalculateSquareRoot();
                    txtDisplay.Text = calculatorEngine.CurrentValue.ToString();
                    break;
                case "±":
                    calculatorEngine.ChangeSign();
                    txtDisplay.Text = calculatorEngine.CurrentValue.ToString();
                    break;
                case "()":
                    if (txtDisplay.Text == "")
                    {
                        // Если строка пуста, добавляем открывающую скобку
                        txtDisplay.Text = "(";
                    }
                    else
                    {
                        // Получаем последний символ в строке
                        char lastChar = txtDisplay.Text.Last();

                        if (char.IsDigit(lastChar))
                        {
                            // Если последний символ - число, добавляем закрывающую скобку
                            txtDisplay.Text += ")";
                        }
                        else if (lastChar == ')' || lastChar == '(')
                        {
                            // Если последний символ - скобка, добавляем открывающую скобку
                            txtDisplay.Text += "(";
                        }
                        // Если последний символ - операция, ничего не делаем
                    }
                    break;
            }
        }
    }

}