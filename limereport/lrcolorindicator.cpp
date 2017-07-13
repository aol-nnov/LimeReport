#include "lrcolorindicator.h"
#include <QPainter>

void ColorIndicator::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.save();
    painter.setBrush(m_color);
    painter.setPen(Qt::gray);
    QRect rect = event->rect().adjusted(3,3,-4,-4);
    rect.setWidth(rect.height());
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(rect);
    painter.restore();
}

ColorIndicator::ColorIndicator(QWidget *parent)
    :QWidget(parent), m_color(Qt::white){
    setAttribute(Qt::WA_StaticContents);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    setFocusPolicy(Qt::NoFocus);
}

QColor ColorIndicator::color() const
{
    return m_color;
}

void ColorIndicator::setColor(const QColor &color)
{
    m_color = color;
    update();
}

QSize ColorIndicator::sizeHint() const
{
    return QSize(20,20);
}
