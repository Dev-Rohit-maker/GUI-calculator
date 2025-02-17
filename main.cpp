#include <SFML/Graphics.hpp>
#include "FONT_PATH.h" // File path for font file
#include <iostream>

double evaluate (const std::string &firstNum, const char operation, const std::string &secondNum)
{
    switch (operation)
    {
        case '^':
            return pow(std::stoi(firstNum), std::stoi(secondNum));
        case '/':
            return static_cast<double>(std::stoi(firstNum) / std::stod(secondNum));
        case '*':
            return std::stoi(firstNum) * std::stoi(secondNum);
        case '-':
            return std::stoi(firstNum) - std::stoi(secondNum);
        case '+':
            return std::stoi(firstNum) + std::stoi(secondNum);
        default:
            return -1;
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(234, 323), "GUI Calculator");
    window.setFramerateLimit(10);

    std::string firstNum = "";
    std::string secondNum = "";
    char operation = 'N';

    // Button shapes
    sf::RectangleShape zeroButton(sf::Vector2f(114, 48));
    sf::RectangleShape oneButton(sf::Vector2f(57, 47));
    sf::RectangleShape twoButton(sf::Vector2f(56, 47));
    sf::RectangleShape threeButton(sf::Vector2f(57, 47));
    sf::RectangleShape fourButton(sf::Vector2f(57, 47));
    sf::RectangleShape fiveButton(sf::Vector2f(56, 47));
    sf::RectangleShape sixButton(sf::Vector2f(57, 47));
    sf::RectangleShape sevenButton(sf::Vector2f(57, 47));
    sf::RectangleShape eightButton(sf::Vector2f(56, 47));
    sf::RectangleShape nineButton(sf::Vector2f(57, 47));
    sf::RectangleShape decimalButton(sf::Vector2f(57, 48));
    sf::RectangleShape clearButton(sf::Vector2f(57, 47));
    sf::RectangleShape signButton(sf::Vector2f(56, 47));
    sf::RectangleShape powerButton(sf::Vector2f(57, 47));
    sf::RectangleShape divideButton(sf::Vector2f(60, 47));
    sf::RectangleShape multiplyButton(sf::Vector2f(60, 47));
    sf::RectangleShape subtractButton(sf::Vector2f(60, 47));
    sf::RectangleShape addButton(sf::Vector2f(60, 47));
    sf::RectangleShape equalButton(sf::Vector2f(60, 48));

    zeroButton.setPosition(sf::Vector2f(0, 274));
    oneButton.setPosition(sf::Vector2f(0, 226));
    twoButton.setPosition(sf::Vector2f(58, 226));
    threeButton.setPosition(sf::Vector2f(115, 226));
    fourButton.setPosition(sf::Vector2f(0, 178));
    fiveButton.setPosition(sf::Vector2f(58, 178));
    sixButton.setPosition(sf::Vector2f(115, 178));
    sevenButton.setPosition(sf::Vector2f(0, 130));
    eightButton.setPosition(sf::Vector2f(58, 130));
    nineButton.setPosition(sf::Vector2f(115, 130));
    decimalButton.setPosition(sf::Vector2f(115, 274));
    clearButton.setPosition(sf::Vector2f(0, 82));
    signButton.setPosition(sf::Vector2f(58, 82));
    powerButton.setPosition(sf::Vector2f(115, 82));
    divideButton.setPosition(sf::Vector2f(173, 82));
    multiplyButton.setPosition(sf::Vector2f(173, 130));
    subtractButton.setPosition(sf::Vector2f(173, 178));
    addButton.setPosition(sf::Vector2f(173, 226));
    equalButton.setPosition(sf::Vector2f(173, 274));

    zeroButton.setFillColor(sf::Color(88, 88, 88));
    oneButton.setFillColor(sf::Color(88, 88, 88));
    twoButton.setFillColor(sf::Color(88, 88, 88));
    threeButton.setFillColor(sf::Color(88, 88, 88));
    fourButton.setFillColor(sf::Color(88, 88, 88));
    fiveButton.setFillColor(sf::Color(88, 88, 88));
    sixButton.setFillColor(sf::Color(88, 88, 88));
    sevenButton.setFillColor(sf::Color(88, 88, 88));
    eightButton.setFillColor(sf::Color(88, 88, 88));
    nineButton.setFillColor(sf::Color(88, 88, 88));
    decimalButton.setFillColor(sf::Color(88, 88, 88));
    clearButton.setFillColor(sf::Color(55, 55, 58));
    powerButton.setFillColor(sf::Color(55, 55, 58));
    signButton.setFillColor(sf::Color(55, 55, 58));
    divideButton.setFillColor(sf::Color(242, 163, 60));
    multiplyButton.setFillColor(sf::Color(242, 163, 60));
    subtractButton.setFillColor(sf::Color(242, 163, 60));
    addButton.setFillColor(sf::Color(242, 163, 60));
    equalButton.setFillColor(sf::Color(242, 163, 60));

    // Text
    sf::Font font;
    if (!font.loadFromFile(FONT_PATH))
        return EXIT_FAILURE;

    sf::Text zeroText("0", font, 32);
    sf::Text oneText("1", font, 32);
    sf::Text twoText("2", font, 32);
    sf::Text threeText("3", font, 32);
    sf::Text fourText("4", font, 32);
    sf::Text fiveText("5", font, 32);
    sf::Text sixText("6", font, 32);
    sf::Text sevenText("7", font, 32);
    sf::Text eightText("8", font, 32);
    sf::Text nineText("9", font, 32);
    sf::Text decimalText(".", font, 32);
    sf::Text clearText("AC", font, 24);
    sf::Text signText_positive("+", font, 24);
    sf::Text signText_separator("/", font, 24);
    sf::Text signText_negative("-", font, 24);
    sf::Text powerText_base("x", font, 26);
    sf::Text powerText_exponent("y", font, 20);
    sf::Text divideText("/", font, 32);
    sf::Text multiplyText("x", font, 32);
    sf::Text subtractText("-", font, 40);
    sf::Text addText("+", font, 32);
    sf::Text equalText("=", font, 32);
    sf::Text answerText("", font, 32);

    zeroText.setPosition(sf::Vector2f(46, 277));
    oneText.setPosition(sf::Vector2f(18, 230));
    twoText.setPosition(sf::Vector2f(75, 230));
    threeText.setPosition(sf::Vector2f(133, 230));
    fourText.setPosition(sf::Vector2f(18, 182));
    fiveText.setPosition(sf::Vector2f(75, 182));
    sixText.setPosition(sf::Vector2f(133, 182));
    sevenText.setPosition(sf::Vector2f(18, 135));
    eightText.setPosition(sf::Vector2f(75, 135));
    nineText.setPosition(sf::Vector2f(133, 135));
    decimalText.setPosition(sf::Vector2f(139, 274));
    clearText.setPosition(sf::Vector2f(12, 90));
    signText_positive.setPosition(sf::Vector2f(69, 86));
    signText_separator.setPosition(sf::Vector2f(78, 90));
    signText_negative.setPosition(sf::Vector2f(87, 95));
    powerText_base.setPosition(sf::Vector2f(130, 90));
    powerText_exponent.setPosition(sf::Vector2f(146, 85));
    divideText.setPosition(sf::Vector2f(195, 86));
    multiplyText.setPosition(sf::Vector2f(194, 131));
    subtractText.setPosition(sf::Vector2f(195, 175));
    addText.setPosition(sf::Vector2f(193, 227));
    equalText.setPosition(sf::Vector2f(193, 277));
    answerText.setPosition(sf::Vector2f(20, 20)); //todo

    // Display GUI
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(38, 38, 38));

        // Buttons
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (sf::Mouse::getPosition(window).x >= 0 &&
                sf::Mouse::getPosition(window).y >= 274 &&
                sf::Mouse::getPosition(window).x <= 114 &&
                sf::Mouse::getPosition(window).y <= 274+48)
                if (operation == 'N')
                    firstNum += "0";
                else
                    secondNum += "0";
            else if (sf::Mouse::getPosition(window).x >= 0 &&
                sf::Mouse::getPosition(window).y >= 226 &&
                sf::Mouse::getPosition(window).x <= 57 &&
                sf::Mouse::getPosition(window).y <= 226+47)
                if (operation == 'N')
                    firstNum += "1";
                else
                    secondNum += "1";
            else if (sf::Mouse::getPosition(window).x >= 58 &&
                sf::Mouse::getPosition(window).y >= 226 &&
                sf::Mouse::getPosition(window).x <= 58+56 &&
                sf::Mouse::getPosition(window).y <= 226+47)
                if (operation == 'N')
                    firstNum += "2";
                else
                    secondNum += "2";
            else if (sf::Mouse::getPosition(window).x >= 115 &&
                sf::Mouse::getPosition(window).y >= 226 &&
                sf::Mouse::getPosition(window).x <= 115+47 &&
                sf::Mouse::getPosition(window).y <= 226+47)
                if (operation == 'N')
                    firstNum += "3";
                else
                    secondNum += "3";
            else if (sf::Mouse::getPosition(window).x >= 0 &&
                sf::Mouse::getPosition(window).y >= 178 &&
                sf::Mouse::getPosition(window).x <= 57 &&
                sf::Mouse::getPosition(window).y <= 178+47)
                if (operation == 'N')
                    firstNum += "4";
                else
                    secondNum += "4";
            else if (sf::Mouse::getPosition(window).x >= 58 &&
                sf::Mouse::getPosition(window).y >= 178 &&
                sf::Mouse::getPosition(window).x <= 58+56 &&
                sf::Mouse::getPosition(window).y <= 178+47)
                if (operation == 'N')
                    firstNum += "5";
                else
                    secondNum += "5";
            else if (sf::Mouse::getPosition(window).x >= 115 &&
                sf::Mouse::getPosition(window).y >= 178 &&
                sf::Mouse::getPosition(window).x <= 115+57 &&
                sf::Mouse::getPosition(window).y <= 178+47)
                if (operation == 'N')
                    firstNum += "6";
                else
                    secondNum += "6";
            else if (sf::Mouse::getPosition(window).x >= 0 &&
                sf::Mouse::getPosition(window).y >= 130 &&
                sf::Mouse::getPosition(window).x <= 57 &&
                sf::Mouse::getPosition(window).y <= 130+47)
                if (operation == 'N')
                    firstNum += "7";
                else
                    secondNum += "7";
            else if (sf::Mouse::getPosition(window).x >= 58 &&
                sf::Mouse::getPosition(window).y >= 130 &&
                sf::Mouse::getPosition(window).x <= 58+56 &&
                sf::Mouse::getPosition(window).y <= 130+47)
                if (operation == 'N')
                    firstNum += "8";
                else
                    secondNum += "8";
            else if (sf::Mouse::getPosition(window).x >= 115 &&
                sf::Mouse::getPosition(window).y >= 130 &&
                sf::Mouse::getPosition(window).x <= 115+57 &&
                sf::Mouse::getPosition(window).y <= 130+47)
                if (operation == 'N')
                    firstNum += "9";
                else
                    secondNum += "9";
            else if (sf::Mouse::getPosition(window).x >= 115 &&
                sf::Mouse::getPosition(window).y >= 274 &&
                sf::Mouse::getPosition(window).x <= 115+57 &&
                sf::Mouse::getPosition(window).y <= 274+48)
                if (operation == 'N')
                    firstNum += ".";
                else
                    secondNum += ".";
            else if (sf::Mouse::getPosition(window).x >= 0 &&
                sf::Mouse::getPosition(window).y >= 82 &&
                sf::Mouse::getPosition(window).x <= 57 &&
                sf::Mouse::getPosition(window).y <= 82+47)
            {
                firstNum = "";
                secondNum = "";
                operation = 'N';
            }
            else if (sf::Mouse::getPosition(window).x >= 58 &&
                sf::Mouse::getPosition(window).y >= 82 &&
                sf::Mouse::getPosition(window).x <= 58+56 &&
                sf::Mouse::getPosition(window).y <= 82+47)
                if (operation == 'N')
                    firstNum = "-" + firstNum;
                else
                    secondNum = "-" + secondNum;
            else if (sf::Mouse::getPosition(window).x >= 115 &&
                sf::Mouse::getPosition(window).y >= 82 &&
                sf::Mouse::getPosition(window).x <= 115+57 &&
                sf::Mouse::getPosition(window).y <= 82+47)
                operation = '^';
            else if (sf::Mouse::getPosition(window).x >= 173 &&
                sf::Mouse::getPosition(window).y >= 82 &&
                sf::Mouse::getPosition(window).x <= 173+60 &&
                sf::Mouse::getPosition(window).y <= 82+47)
                operation = '/';
            else if (sf::Mouse::getPosition(window).x >= 173 &&
                sf::Mouse::getPosition(window).y >= 130 &&
                sf::Mouse::getPosition(window).x <= 173+60 &&
                sf::Mouse::getPosition(window).y <= 130+47)
                operation = '*';
            else if (sf::Mouse::getPosition(window).x >= 173 &&
                sf::Mouse::getPosition(window).y >= 178 &&
                sf::Mouse::getPosition(window).x <= 173+60 &&
                sf::Mouse::getPosition(window).y <= 178+47)
                operation = '-';
            else if (sf::Mouse::getPosition(window).x >= 173 &&
                sf::Mouse::getPosition(window).y >= 226 &&
                sf::Mouse::getPosition(window).x <= 173+60 &&
                sf::Mouse::getPosition(window).y <= 226+47)
                operation = '+';
            else if (sf::Mouse::getPosition(window).x >= 173 &&
                sf::Mouse::getPosition(window).y >= 274 &&
                sf::Mouse::getPosition(window).x <= 173+60 &&
                sf::Mouse::getPosition(window).y <= 274+48)
            {
                double answer = evaluate(firstNum, operation, secondNum);
                std::cout << firstNum << operation << secondNum << std::endl;
                std::cout << answer << std::endl;
                answerText.setString(std::to_string(answer));
                firstNum = "";
                secondNum = "";
                operation = 'N';
            }

        }

        // Draw buttons
        window.draw(zeroButton);
        window.draw(oneButton);
        window.draw(twoButton);
        window.draw(threeButton);
        window.draw(fourButton);
        window.draw(fiveButton);
        window.draw(sixButton);
        window.draw(sevenButton);
        window.draw(eightButton);
        window.draw(nineButton);
        window.draw(decimalButton);
        window.draw(clearButton);
        window.draw(signButton);
        window.draw(powerButton);
        window.draw(divideButton);
        window.draw(multiplyButton);
        window.draw(subtractButton);
        window.draw(addButton);
        window.draw(equalButton);

        // Draw text
        window.draw(zeroText);
        window.draw(oneText);
        window.draw(twoText);
        window.draw(threeText);
        window.draw(fourText);
        window.draw(fiveText);
        window.draw(sixText);
        window.draw(sevenText);
        window.draw(eightText);
        window.draw(nineText);
        window.draw(decimalText);
        window.draw(clearText);
        window.draw(signText_positive);
        window.draw(signText_separator);
        window.draw(signText_negative);
        window.draw(powerText_base);
        window.draw(powerText_exponent);
        window.draw(divideText);
        window.draw(multiplyText);
        window.draw(subtractText);
        window.draw(addText);
        window.draw(equalText);
        window.draw(answerText);

        window.display();
    }

}
