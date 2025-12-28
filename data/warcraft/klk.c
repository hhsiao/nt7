// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("萬歲走[2;37;0m[2;37;0m", ({"klkd"}));        
        set("gender", "女性");                
        set("long", "誰有[2;37;0m
它是六位數字的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "klk");
        set("owner_name", "六位數字");
        set_temp("owner", "klk");
        set_temp("owner_name", "六位數字");
        ::setup();
}
