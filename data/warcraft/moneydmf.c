// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是黑紗的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "moneydmf");
        set("owner_name", "黑紗");
        set_temp("owner", "moneydmf");
        set_temp("owner_name", "黑紗");
        ::setup();
}
