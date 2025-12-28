// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鳳凰[2;37;0m[2;37;0m", ({"que"}));        
        set("gender", "女性");                
        set("long", "白鳥之王[2;37;0m
它是王頗豐的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ttjian");
        set("owner_name", "王頗豐");
        set_temp("owner", "ttjian");
        set_temp("owner_name", "王頗豐");
        ::setup();
}
