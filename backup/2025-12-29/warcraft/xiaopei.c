// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m仙子[2;37;0m[2;37;0m", ({"bag"}));        
        set("gender", "男性");                
        set("long", "一隻張牙舞爪的小白龍[2;37;0m
它是花無缺的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaopei");
        set("owner_name", "花無缺");
        set_temp("owner", "xiaopei");
        set_temp("owner_name", "花無缺");
        ::setup();
}
