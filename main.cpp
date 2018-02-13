#include <QApplication>
#include <QDebug>
#include <iostream>
#include "core/evaluator.h"

int main(int argc, char *argv[])
{
    Evaluator *m_eval = Evaluator::instance();

    std::string expression;

    while (std::cin >> expression) {
        const QString exp = QString::fromStdString(expression);
        m_eval->setExpression(exp);

        Quantity ans = m_eval->evalUpdateAns();
        const QString result = DMath::format(ans, Quantity::Format::Fixed());

        qDebug() << result;
    }

    return 0;
}
