// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("加快[2;37;0m[2;37;0m", ({"mamama"}));        
        set("gender", "女性");                
        set("long", "的金額快樂[2;37;0m
它是大輪飛豬的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "qmqmqma");
        set("owner_name", "大輪飛豬");
        set_temp("owner", "qmqmqma");
        set_temp("owner_name", "大輪飛豬");
        ::setup();
}
