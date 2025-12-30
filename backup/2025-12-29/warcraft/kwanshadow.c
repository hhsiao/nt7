// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m小紅[2;37;0m[2;37;0m", ({"xiaohong"}));        
        set("gender", "女性");                
        set("long", "一隻紅彤彤的朱雀[2;37;0m
它是小玉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "kwanshadow");
        set("owner_name", "小玉");
        set_temp("owner", "kwanshadow");
        set_temp("owner_name", "小玉");
        ::setup();
}
