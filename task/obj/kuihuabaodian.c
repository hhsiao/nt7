
#include <ansi.h>
inherit TASK;
void create()
{
    set_name( HIR "葵花寶典" NOR, ({ "kuihua baodian" }) );
    set_weight(1);
    if( clonep() )
            destruct(this_object());
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "這是一本葵花寶典。\n");
          }
    set("owner", "葵花太監");
    setup();
}

