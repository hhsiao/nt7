// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m小溪龍[2;37;0m[2;37;0m", ({"aaaaa"}));        
        set("gender", "男性");                
        set("long", "一條小河裡的龍[2;37;0m
它是血無痕的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xwh");
        set("owner_name", "血無痕");
        set_temp("owner", "xwh");
        set_temp("owner_name", "血無痕");
        ::setup();
}
