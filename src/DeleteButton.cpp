#include "include/DeleteButton.h"
#include "include/ErrorOkWindow.h"

DeleteButton::DeleteButton(DataTable *&table, int x, int y, int w, int h,
                           const char *l)
    : OFLButton(x, y, w, h, l), table(table)

{}

void DeleteButton::Press() { deleteField(); };
void DeleteButton::deleteField() {
  if (!table->checkAdmin()) {
    admin = new AdminWindow(table, 0, 0, "Админ");
  } else {

    if (table->getActiveRow() == -1) {
      err_win = new ErrorOkWindow(0, 0, "Не выбран гражданин для удаления!",
                                  "Окно ошибок");
      return;
    }
    table->deleteById();
    table->undoTable();
  }
}
