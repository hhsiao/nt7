// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("上古神龍[2;37;0m[2;37;0m", ({"dragon"}));        
        set("gender", "女性");                
        set("long", "一之神獸[2;37;0m
它是瘋子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "crazy");
        set("owner_name", "瘋子");
        set_temp("owner", "crazy");
        set_temp("owner_name", "瘋子");
        ::setup();
}
