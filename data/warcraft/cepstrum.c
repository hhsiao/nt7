// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("翱翔[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "翱翔在天的朱雀[2;37;0m
它是張裕的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cepstrum");
        set("owner_name", "張裕");
        set_temp("owner", "cepstrum");
        set_temp("owner_name", "張裕");
        ::setup();
}
