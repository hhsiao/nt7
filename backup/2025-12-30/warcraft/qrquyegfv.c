// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是時雄香的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "qrquyegfv");
        set("owner_name", "時雄香");
        set_temp("owner", "qrquyegfv");
        set_temp("owner_name", "時雄香");
        ::setup();
}
