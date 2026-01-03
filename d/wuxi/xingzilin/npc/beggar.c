// This program is a part of NITAN MudLIB
// redl 2012/11/1
#include <ansi.h>
#include "../cnpc.h"

inherit NPC;

void create() {
    set_name(NOR "無名老乞丐" NOR, ({ "old beggar", "beggar" }) );
    set("gender", "男性");
    set("age", 80);
    set("long", NOR"    這是一個神秘的老乞丐，不知道為什麼悄悄躲在這山洞裡。"NOR);
    set("attitude", "peaceful");
    set("str", 50);
    set("con", 30);
    set("int", 24);
    set("dex", 30);
    set("per", 13);

    set("chat_chance", 3);
    set("chat_msg", ({
        CYN"老乞丐狠狠地道：該死的四大惡人，投靠一品堂助紂為虐。\n"NOR ,
        CYN"老乞丐自傲說道：丐幫為中原第一大幫，豈能向一品堂伏低。\n"NOR ,
        CYN"老乞丐喃喃念道：今丐幫已檄告天下各路英豪，重金懸賞四大惡人的頭顱。\n"NOR ,
        CYN"老乞丐微笑著說：凡獲惡人首級一枚者，皆可於我這裡兌換獎勵。\n"NOR
    }) );

    set("combat_exp", 10000000);

    setup();

}

int accept_object(object me, object obj) {
    int amount, exp;

    if(!query("xzz/headlv", obj) )
    {
        tell_object(me, CYN "老乞丐搖了搖頭，對你說道：我只要惡人首級。\n" NOR);
        return 0;
    }

    if(query("level", me) < 10)
    {
        tell_object(me, CYN "老乞丐奇怪地看了你一眼說：憑你這本事也能拿下四大惡人？\n" NOR);
        return 0;
    }

    exp = GIVEHEAD_GIFT_EXP;

    if (function_exists("query_amount", obj))
        amount = obj->query_amount();
    else
        amount = 1;

    exp *= amount;


    if(query("level", me) <= 30 )   //1000w+ exp後方可獲得正常獎勵，方便森林副本後接本任務
    {
    }
    else if(query("level", me) <= 60 )
    {
        exp /= 2;
    }
    else if(query("level", me) <= 100 )     //放寬此處，小小刺激培養大米來割頭，和小規模衝突
    {
        exp /= 4;
    }
    else    //中後期的練功id，已經完全看不上這100點了
    {
        exp = 100;
    }

    exp = invert_reborngiftd(me, exp);

    GIFT_D->work_bonus(me, ([ "exp": exp, "pot": exp / 5, "mar": exp / 16, "score": exp / 100 ]));  //pot獎勵不可太多，造成亂選亂學skill

    destruct(obj);
    return 1;
}
