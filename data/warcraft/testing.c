// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m試驗工具[2;37;0m[2;37;0m", ({"tool"}));        
        set("gender", "女性");                
        set("long", "阿[2;37;0m
它是試驗品的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "testing");
        set("owner_name", "試驗品");
        set_temp("owner", "testing");
        set_temp("owner_name", "試驗品");
        ::setup();
}
