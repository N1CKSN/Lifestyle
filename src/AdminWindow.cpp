#include "include/AdminWindow.h"
#include <FL/Enumerations.H>

enum { window_w = 250, window_h = 120, inp_w = 220, but_w = 90 };

AdminWindow::AdminWindow(DataTable*& table, int x, int y, const char* l)
    : OFLWindow(x, y, window_w, window_h, l), table(table)
{
    begin();
    password = new Fl_Secret_Input(window_w / 2 - inp_w / 2, button_h, inp_w,
                                   button_h, "Пароль:");

    password->align(FL_ALIGN_CENTER);

    conf_but = new ConfirmButton(this, window_w / 2 - but_w / 2, button_h * 3,
                                 but_w, button_h, "Подтвердить");
    conf_but->align(FL_ALIGN_CENTER);

    conf_but->labelsize(12);
    set_modal();
    show();
    end();
}

AdminWindow::~AdminWindow()
{
    delete password;
    delete conf_but;
}

void AdminWindow::insertInpValues()
{
    std::string pass = password->value();
    if (this->PASSWORD != pass) {
        err_win = new ErrorOkWindow(0, 0, "Неверный пароль!", "Окно ошибок");
        return;
    }
    else {
        table->setAdmin();
        table->undoTable();
    }
}
void AdminWindow::Interaction()
{
    hide();
    if (Fl::event() == FL_CLOSE) { Fl::delete_widget(this); }
    else {
        insertInpValues();
    }
}
