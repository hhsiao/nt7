// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛天[2;37;0m[2;37;0m", ({"qqqq"}));        
        set("gender", "男性");                
        set("long", "一隻朱雀[2;37;0m
它是風雲的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wlan");
        set("owner_name", "風雲");
        set_temp("owner", "wlan");
        set_temp("owner_name", "風雲");
        ::setup();
}
