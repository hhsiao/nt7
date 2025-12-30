// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龍[2;37;0m[2;37;0m", ({"xql"}));        
        set("gender", "男性");                
        set("long", "圖騰[2;37;0m
它是飛鳥的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lmmlz");
        set("owner_name", "飛鳥");
        set_temp("owner", "lmmlz");
        set_temp("owner_name", "飛鳥");
        ::setup();
}
