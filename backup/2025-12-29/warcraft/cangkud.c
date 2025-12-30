// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m小墨[2;37;0m[2;37;0m", ({"xxm"}));        
        set("gender", "女性");                
        set("long", "小鳥[2;37;0m
它是衣倉庫的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cangkud");
        set("owner_name", "衣倉庫");
        set_temp("owner", "cangkud");
        set_temp("owner_name", "衣倉庫");
        ::setup();
}
