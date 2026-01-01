#include "herb.h"

void create()
{
        set_name(HIY "千金子" NOR, ({ "qian jinzi", "qian", "jinzi", "herb_qianjinzi" }));
        set("long", HIY "千金子是常見的中藥藥材。\n" NOR);
                set("base_unit", "顆");
                set("base_value", 3000);
                set("base_weight", 20);
        setup();
}
