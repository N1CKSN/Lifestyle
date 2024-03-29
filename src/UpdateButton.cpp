#include "include/UpdateButton.h"

UpdateButton::UpdateButton(DataTable *&table, int x, int y, int w, int h,
                           const char *l)
    : OFLButton(x, y, w, h, l), table(table) {}

void UpdateButton::Press() { CreateWin(); };

void UpdateButton::CreateWin() {
  if (!table->checkAdmin()) {
    admin = new AdminWindow(table, 0, 0, "Админ");
  } else {

    if (table->getActiveRow() == -1) {
      ErrorOkWindow *err_win = new ErrorOkWindow(
          0, 0, "Не выбран гражданин для изменения!", "Окно ошибок");
      return;
    }
    std::cout << active_row << "\n";
    win = new UpdateWindow(table, 0, 0, "Окно изменения");
  }
}
