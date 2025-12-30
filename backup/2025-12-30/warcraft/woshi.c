// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("書[2;37;0m[2;37;0m", ({"shui"}));        
        set("gender", "女性");                
        set("long", "書[2;37;0m
它是無金額的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "woshi");
        set("owner_name", "無金額");
        set_temp("owner", "woshi");
        set_temp("owner_name", "無金額");
        ::setup();
}
