// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m張蠢龍[2;37;0m[2;37;0m", ({"lcnely"}));        
        set("gender", "男性");                
        set("long", "張椿龍大王的寵物，也不要瞎騎，小心你的JJ被它的菊給夾掉。[2;37;0m
它是張椿龍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "idle");
        set("owner_name", "張椿龍");
        set_temp("owner", "idle");
        set_temp("owner_name", "張椿龍");
        ::setup();
}
