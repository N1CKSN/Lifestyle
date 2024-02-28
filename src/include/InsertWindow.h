#pragma once

#include "ConfirmButton.h"
#include "DataTable.h"
#include "ErrorOkWindow.h"
#include "OFLWindow.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>

enum {
  ins_win_h = 200,
  ins_win_w = 450,
};

enum {
  trener_inp_w = 80,
  aboniment_inp_w = trener_inp_w,
  conf_button_w = trener_inp_w + 10,
  sp_inp_w = 3 * aboniment_inp_w,
  full_name_inp_w = sp_inp_w + trener_inp_w + aboniment_inp_w + spacing_x * 2,
  number_inp_w = trener_inp_w + sp_inp_w

};

class InsertWindow : public OFLWindow {
public:
  InsertWindow(DataTable *&table, int x, int y, const char *l);

  virtual ~InsertWindow();

  void insertInpValues();

private:
  void Interaction() override;

protected:
  Fl_Input *number_inp;
  Fl_Input *full_name_inp;
  Fl_Input *sp_inp;
  Fl_Input *aboniment_inp;
  Fl_Input *trener_inp;
  DataTable *&table;
  ConfirmButton *conf_but;
  ErrorOkWindow *err_win;
};
