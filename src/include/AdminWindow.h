#pragma once
#include "ConfirmButton.h"
#include "DataTable.h"
#include "ErrorOkWindow.h"
#include "FL/Fl_Secret_Input.H"
#include "OFLWindow.h"
#include <FL/Fl_Box.H>

class AdminWindow : public OFLWindow {
  const std::string PASSWORD = "password";

public:
  AdminWindow(DataTable *&table, int x, int y, const char *l);

  virtual ~AdminWindow();

  void insertInpValues();

private:
  DataTable *&table;
  ConfirmButton *conf_but;
  ErrorOkWindow *err_win;
  Fl_Input *password;
  bool isActive = false;
  void Interaction() override;

protected:
};
