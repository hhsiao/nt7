// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m蛇龜[2;37;0m[2;37;0m", ({"shegui"}));        
        set("gender", "男性");                
        set("long", "龍頭蛇尾的異獸[2;37;0m
它是寒凌宇的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "gins");
        set("owner_name", "寒凌宇");
        set_temp("owner", "gins");
        set_temp("owner_name", "寒凌宇");
        ::setup();
}
