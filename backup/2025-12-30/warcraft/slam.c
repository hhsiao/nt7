// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("天使之翼[2;37;0m[2;37;0m", ({"ronaldo"}));        
        set("gender", "女性");                
        set("long", "來歷不明的生物, 擁有神奇的力量[2;37;0m
它是浪子丹的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "slam");
        set("owner_name", "浪子丹");
        set_temp("owner", "slam");
        set_temp("owner_name", "浪子丹");
        ::setup();
}
