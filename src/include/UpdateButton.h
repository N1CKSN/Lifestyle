#pragma once

#include "AdminWindow.h"
#include "DataTable.h"
#include "ErrorOkWindow.h"
#include "OFLButton.h"
#include "UpdateWindow.h"

class UpdateButton : public OFLButton {
public:
  UpdateButton(DataTable *&table, int x, int y, int w, int h,
               const char *l = "");

  void Press();
  void CreateWin();

private:
  InsertWindow *win;
  DataTable *&table;
  AdminWindow *admin;
  int active_row;
};
