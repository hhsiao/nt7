// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m玲瓏[2;37;0m[2;37;0m", ({"firebird"}));        
        set("gender", "女性");                
        set("long", "一隻紅色的大鳥，很大，很紅！[2;37;0m
它是慕容無雙的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "only");
        set("owner_name", "慕容無雙");
        set_temp("owner", "only");
        set_temp("owner_name", "慕容無雙");
        ::setup();
}
