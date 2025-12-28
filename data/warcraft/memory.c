// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m紙夜[2;37;0m[2;37;0m", ({"paper"}));        
        set("gender", "女性");                
        set("long", "一片薄如蠶絲的紙頁[2;37;0m
它是回憶的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "memory");
        set("owner_name", "回憶");
        set_temp("owner", "memory");
        set_temp("owner_name", "回憶");
        ::setup();
}
