// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m聖龍[2;37;0m[2;37;0m", ({"lauslbb"}));        
        set("gender", "女性");                
        set("long", "我的寶貝[2;37;0m
它是不毒邪龍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lausl");
        set("owner_name", "不毒邪龍");
        set_temp("owner", "lausl");
        set_temp("owner_name", "不毒邪龍");
        ::setup();
}
