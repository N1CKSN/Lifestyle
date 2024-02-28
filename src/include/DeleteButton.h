#pragma once

#include "AdminWindow.h"
#include "DataTable.h"
#include "ErrorOkWindow.h"
#include "OFLButton.h"

class DeleteButton : public OFLButton {
public:
  DeleteButton(DataTable *&table, int x, int y, int w, int h,
               const char *l = "");

  void Press() override;
  void deleteField();

private:
  DataTable *&table;
  AdminWindow *admin;
  ErrorOkWindow *err_win;
};
