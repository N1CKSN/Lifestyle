#include "include/InsertWindow.h"

InsertWindow::InsertWindow(DataTable*& table, int x, int y, const char* l)
    : OFLWindow(x, y, ins_win_w, ins_win_h, l), table(table)
{
    begin();
    number_inp
        = new Fl_Input(spacing_x, button_h, number_inp_w, button_h, "Телефон:");
    number_inp->align(FL_ALIGN_TOP_LEFT);

    number_inp->value("+7 ");
    full_name_inp = new Fl_Input(spacing_x, button_h * 3, full_name_inp_w,
                                 button_h, "Фио:");
    full_name_inp->align(FL_ALIGN_TOP_LEFT);

    sp_inp = new Fl_Input(spacing_x, button_h * 5, sp_inp_w, button_h,
                              "Тренер:");
    sp_inp->align(FL_ALIGN_TOP_LEFT);

    aboniment_inp = new Fl_Input(sp_inp_w + spacing_x * 2, button_h * 5,
                             aboniment_inp_w, button_h, "Абонимент:");
    aboniment_inp->align(FL_ALIGN_TOP_LEFT);

    trener_inp = new Fl_Input(sp_inp_w + aboniment_inp_w + spacing_x * 3,
                            button_h * 5, trener_inp_w, button_h, "Спорт пит:");
    trener_inp->align(FL_ALIGN_TOP_LEFT);

    conf_but = new ConfirmButton(this, number_inp_w + spacing_x * 2, button_h,
                                 conf_button_w, button_h, "Подтвердить");
    conf_but->labelsize(13);
    set_modal();
    show();
    end();
}

InsertWindow::~InsertWindow()
{
    delete conf_but;
    delete number_inp;
    delete full_name_inp;
    delete sp_inp;
    delete aboniment_inp;
    delete trener_inp;
}

void InsertWindow::insertInpValues()
{
    std::vector<std::string> val_vec(table->sw->getRowCount());
    val_vec[1] = number_inp->value();
    val_vec[2] = full_name_inp->value();
    val_vec[3] = sp_inp->value();
    val_vec[4] = aboniment_inp->value();
    val_vec[5] = trener_inp->value();

    if (table->sw->insert(val_vec) == SQLITE_CONSTRAINT) {
        err_win = new ErrorOkWindow(0, 0, "Введен дубликат номера телефона!",
                                    "Окно ошибок");
        return;
    }
    table->undoTable();
}
void InsertWindow::Interaction()
{
    std::string number_inp_str = number_inp->value();
    std::string full_name_inp_str = full_name_inp->value();
    std::string sp_inp_str = sp_inp->value();
    std::string aboniment_inp_str = aboniment_inp->value();
    std::string trener_inp_str = trener_inp->value();
    hide();
    if (Fl::event() == FL_CLOSE) { Fl::delete_widget(this); }
    else {
        insertInpValues();
    }
}
