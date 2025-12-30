// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m剎[1;33m那[2;37;0m[1;31m邪惡[2;37;0m[2;37;0m", ({"evil"}));        
        set("gender", "男性");                
        set("long", "剎那間，萌生，邪惡的念頭... [2;37;0m
它是邪惡瞬間的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "evillive");
        set("owner_name", "邪惡瞬間");
        set_temp("owner", "evillive");
        set_temp("owner_name", "邪惡瞬間");
        ::setup();
}
