#include "include/InsertButton.h"
#include "include/AdminWindow.h"

InsertButton::InsertButton(DataTable *&table, int x, int y, int w, int h,
                           const char *l)
    : OFLButton(x, y, w, h, l), table(table) {}

void InsertButton::Press() { CreateWin(); };

void InsertButton::CreateWin() {
  if (!table->checkAdmin()) {
    admin = new AdminWindow(table, 0, 0, "Админ");
  } else {
    win = new InsertWindow(table, 0, 0, "Окно вставки");
  }
}
