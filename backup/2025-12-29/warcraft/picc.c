// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m蝙蝠車[2;37;0m[2;37;0m", ({"picca"}));        
        set("gender", "女性");                
        set("long", "多少點[2;37;0m
它是平安保險的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "picc");
        set("owner_name", "平安保險");
        set_temp("owner", "picc");
        set_temp("owner_name", "平安保險");
        ::setup();
}
