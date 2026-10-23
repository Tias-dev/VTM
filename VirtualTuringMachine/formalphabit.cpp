#include "formalphabit.h"

#include <QDebug>

#include "interfaces/IVMTEnvironment.h"
#include "screentools.h"
#include "ui_formalphabit.h"
#include "utils/ui.h"
#include "vmttheme.h"

FormAlphabit::FormAlphabit(IVMTAlphabitSource* alphabit_source,
                           IVMTEnvironment* environment, QWidget* parent)
    : QWidget(parent),
      ui(new Ui::FormAlphabit),
      _alphabit_source(alphabit_source),
      _environment(environment) {
    ui->setupUi(this);
    VmtTheme::polishWidgetTree(this);

    if (!_alphabit_source->GetAlphabit())
        throw std::logic_error("FormAlphabit::FormAlphabit No alphabit given!");
    QString str = _alphabit_source->GetAlphabit()->ToString();

    ui->frame->setLayout(&_layout);
    ui->frame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    _layout.setContentsMargins(5, 5, 5, 5);

    ScreenTools st;
    const QString style = VmtTheme::alphabetButtonStyle();

    const int count = qMin(static_cast<int>(str.size()), 256);
    for (int i = 0; i < count; ++i) {
        QToolButton* label = &_buttons[i];
        label->setProperty("sign", QString(QChar(str[i])));
        label->setText(QString(utils::ui::escapeChar(str[i])));
        label->setCheckable(true);
        label->setStyleSheet(style);

        st.ResizeButton(label);
        if (_alphabit_source->IsEnabled(str[i].toLatin1()))
            label->setChecked(true);
        else
            label->setChecked(false);

        QObject::connect(label, SIGNAL(clicked()), this, SLOT(onRefClicked()));
        _layout.addWidget(label);
        if (_alphabit_source->IsSingleChar()) _group.addButton(label);
    }
}

void FormAlphabit::onRefClicked() {
    QToolButton* clicked_button = dynamic_cast<QToolButton*>(sender());
    if (clicked_button) {
        QVariant var = clicked_button->property("sign");
        QString sign = var.toString();
        qDebug() << "Click";
        if (_alphabit_source) {
            if (ctrlPressed) {
                if (_alphabit_source->IsEnabled(sign[0])) {
                    _alphabit_source->SetDisableAllExclude(sign[0],
                                                           _environment);
                    for (QToolButton& button : _buttons) {
                        button.setChecked(button.property("sign") == sign);
                    }
                } else {
                    _alphabit_source->SetEnableAllExclude(sign[0],
                                                          _environment);
                    for (QToolButton& button : _buttons) {
                        button.setChecked(button.property("sign") != sign);
                    }
                }
            } else {
                _alphabit_source->SetEnable(sign[0].toLatin1(),
                                            clicked_button->isChecked(),
                                            _environment);
            }
            _environment->Repaint(QRect());
        }
    }
}

FormAlphabit::~FormAlphabit() { delete ui; }
