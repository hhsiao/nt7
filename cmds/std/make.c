// make.c

#include <ansi.h>
#include <medical.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object qm;
        object hob;
        string med;
        mapping make;
        mapping req;
        mapping herb;
        string *ks;
        object *hlist;
        string msg;
        int only_list;
        int i;
        object hob2;

        if (! arg)
        {
                make=query("can_make", me);
                if (! mapp(make))
                        return notify_fail("你現在不會制任何藥物。\n");

                ks = keys(make);
                msg = "你現在已經會制";
                if (sizeof(ks) >= 2)
                        msg += implode(ks[0..sizeof(ks) - 2], "、") +
                                "和" + ks[sizeof(ks) - 1] + "了。\n";
                else
                        msg += ks[0] + "了。\n";
                msg = sort_string(msg, 64);
                write(msg);
                return 1;
        }

        // only for list?
        only_list = sscanf(arg, "%s ?", arg);

        if( !stringp(med=query("can_make/"+arg, me)) )
                return notify_fail("你還不會配這種藥啊！\n");

        // The player can only make the medicine under the /clone/medicine,
        // nothing, but for save memory.
        med = MEDICINE(med);
        if (file_size(med + ".c") < 0)
                return notify_fail("這種藥方好像已經失傳了？你還是問問巫師吧。\n");
                
        //tell_object(me, "test:" + med + "\n");
        if (med == "/clone/medicine/yuqing") {
/*
                        if( (query("online_time", me) > 86400 * 31) ) {
                                if (!sscanf(base_name(environment(me)), "/d/dongtian/%*s/liandanfang"))
                                return notify_fail("你不是新人了，找個洞天煉丹房去煉製吧。\n");
                } else {        
                        if (!sscanf(base_name(environment(me)), "/d/dongtian/%*s/liandanfang") && 
                                !sscanf(base_name(environment(me)), "/temp/qroom/%*s"))
                                return notify_fail("這種丹藥從飛星法陣進入天生石樑最裡面可以煉製。\n");
                }
*/
                if (query("doing", me) && !interactive(me))
                        "/cmds/usr/scheme.c"->cancel_schedule(me);
        }

        if (! mapp(req = query("mixture", get_object(med))))
                return notify_fail(med->name() + "好像無法配製...\n");

        if (! mapp(herb = req["herb"]))
                return notify_fail(med->name() + "需要什麼原料呢...\n");

        if (only_list)
        {
                // show herb
                write("煉製" + arg + "需要以下這些藥材：\n");
                ks = keys(herb);
                for (i = 0; i < sizeof(ks); i++)
                {
                        write(chinese_number(herb[ks[i]]) + query("base_unit", get_object(HERB(ks[i]))) +
                              HERB(ks[i])->name() + "\n");
                }
                return 1;
        }

        if (me->is_fighting())
                return notify_fail("打架的時候你還有閒工夫配藥？\n");

        if (me->is_busy())
                return notify_fail("還是先把手頭的事情忙完吧。\n");

        if( query("no_fight", environment(me)) && 0 )
                return notify_fail("你在這裡製藥只怕要打擾到別人。\n");

        qm=query_temp("handing", me);
        if (! qm)
                return notify_fail("你的先把能夠磨藥的研缽拿(hand)在手上才行。\n");

        if (! qm->can_make_medicine())
                return notify_fail(qm->name() + "好像無法發揮研缽的作用吧。\n");

        if (sizeof(all_inventory(qm)) > 0)
                return notify_fail("你還是先把" + qm->name() + "裡面的東西拿出來再說。\n");

        if( query("jing", me)<query("max_jing", me)*7/10 )
                return notify_fail("你現在精神難以集中，無法配藥。\n");

        ks = keys(req) - ({ "herb", "neili", "jing", "jingli", "min_level", "time" });

        // check skills
        for (i = 0; i < sizeof(ks); i++)
                if (me->query_skillo(ks[i], 1) < req[ks[i]])
                        return notify_fail("你的" + to_chinese(ks[i]) +
                                           "水平不夠，還無法調劑" +
                                           med->name() + "。\n");
    
    //血脈丹以外可以不耗藥材                                       
        if ((!get_object(med)->is_xuemai_dan()) && base_name(qm)=="/clone/goods/tiandilu") {
                        switch(random(3))
                                {
                                        case 0:
                                                hob2 = present("sheli zi", me);
                                                if ((!hob2) || base_name(hob2)!="/clone/fam/pill/sheli1")
                                                        hob2 = 0;
                                                set_temp("tiandilu/type", 1, me);       
                                                break;
                                        case 1:
                                                hob2 = present("xue puti", me);
                                                if ((!hob2) || base_name(hob2)!="/clone/fam/pill/puti1")
                                                        hob2 = 0;
                                                set_temp("tiandilu/type", 2, me);       
                                                break;
                                        case 2:
                                                hob2 = present("haotian guo", me);
                                                if ((!hob2) || base_name(hob2)!="/clone/fam/pill/linghui1")
                                                        hob2 = 0;
                                                set_temp("tiandilu/type", 3, me);
                                                break;
                                }
        }
        if (hob2) {// && 
                //query_temp("tiandilu/cdtime", me) < time()) {
                        //set_temp("tiandilu/cdtime", time() + 21 + random(10), me);
                        message_vision(NOR CYN "$N拿出一" + query("base_unit", hob2) + hob2->name() + NOR CYN "塞進嘴裡幾把嚼爛，\n緊跟著噴出一口靈氣灌注到$n" NOR CYN "裡代替藥材。\n" NOR, me, qm);
                        hob2->add_amount(-1);
        } else {
                delete_temp("tiandilu/type", me);

        // check herb
        ks = keys(herb);
        hlist = allocate(sizeof(ks));
        for (i = 0; i < sizeof(ks); i++)
        {
                hob = present("herb_" + ks[i], me);
                            if (! hob || (hob->query_amount() < herb[ks[i]] && (base_name(hob)!="/clone/herb/dimai" && base_name(hob)!="/clone/herb/yulu" )) )
                {
                        if (file_size(HERB(ks[i]) + ".c") < 0)
                        {
                                write("沒有(" + ks[i] + ")這種藥材啊！"
                                      "怎麼回事？\n");
                                return 1;
                        }
                        return notify_fail("你點了點藥材，發現" +
                                           HERB(ks[i])->name() +
                                           "的分量還不夠。\n");
                }
                hlist[i] = hob;
        }

        // decrease herb
        msg = "你選出";
        for (i = 0; i < sizeof(ks); i++)
        {
                if (i) msg += "、";
                msg += chinese_number(herb[ks[i]]) +
                       query("base_unit", hlist[i])+
                       hlist[i]->name();
                hlist[i]->add_amount(-herb[ks[i]]);
              if( base_name(hlist[i])=="/clone/herb/dimai" || base_name(hlist[i])=="/clone/herb/yulu")
              destruct(hlist[i]);
        }
        msg += "，然後小心翼翼的把它們放到" + qm->name() + "裡面，開始製藥。\n";
        msg = sort_string(msg, 64);
        write(msg);
    }
    
        message("vision", me->name() + "東摸摸，西弄弄，不知道在幹啥。\n",
                environment(me), ({ me }));
        me->start_busy(bind((:call_other, __FILE__, "making" :), me),
                       bind((:call_other, __FILE__, "halt_make" :), me));
        me->set_short_desc("正在專心致志的煉製藥物。");
        set_temp("pending/making", 0, me);
        set_temp("making/medicine", med, me);
        if (base_name(qm)=="/clone/goods/tiandilu") 
                set_temp("making/time", req["time"] / 2, me);
        else
                set_temp("making/time", req["time"], me);
        set_temp("making/require", req, me);
        set_temp("making/container", qm, me);
        return 1;
}

int stop_making(object me)
{
        object qm;
        delete_temp("making", me);
        delete_temp("pending/making", me);
        me->set_short_desc(0);
        if (qm = query_temp("tiandilu/bomb", me)) {
                        message_vision(NOR BLINK HIY "\n$N手中的" + qm->name() + NOR BLINK HIY "“嘭~~”地一聲，爆炸了。\n\n" NOR , me);
                        if (!random(100)) {
                                set_temp("die_reason", "被"+ qm->name() +"炸得四分五裂了", me);
                                me->die(qm);
                        }
                        destruct(qm);
        }
        return 0;
}

int making(object me)
{
        int step;
        int level;
        mapping req;
        string msg_me, msg_out;
        string med, obname;
        object ob, ob2;
        object qm;
                int flag_jiu;

        step=query_temp("pending/making", me);
        req=query_temp("making/require", me);
        med=query_temp("making/medicine", me);
        qm=query_temp("making/container", me);
        if( qm != query_temp("handing", me) )
        {
                write("嗯？研缽呢...？我的研缽！\n");
                return stop_making(me);
        }
        if (base_name(qm)=="/clone/goods/jiulonglu") flag_jiu = 1;
        if (base_name(qm)=="/clone/goods/tiandilu") flag_jiu = 2;
        
        if (flag_jiu>1 && step>0 && step<3 && (!random(15)) && random(me->query_kar())>10 && 
                query_temp("tiandilu/cdtime", me) < time() ) {
                set_temp("tiandilu/cdtime", time() + 11 + random(25), me);
                step = 8;
                message_vision(NOR CYN "天空無數紫電降下，$N" NOR CYN "的" + HIC "天" HIK "地" HIR "洪爐" + NOR CYN "“嗡嗡~~”地透出聲聲龍吟。\n" , me);
        }

        switch (step)
        {
        default:
                step = 0;
                msg_me = "你拿起棒杵，慢慢的搗著" + qm->name() + "裡面的藥材。\n";
                msg_out = "$N拿起棒杵叮咣叮咣的搗得很起勁。\n";
                break;
        case 1:
                msg_me = "撲哧撲哧，藥材眼見變成了一塊塊小碎塊。\n";
                msg_out = "$N沒完沒了的搗鼓。\n";
                break;
        case 2:
                msg_me = "你輕輕的研磨著藥材，讓它越來越細。\n";
                msg_out = "$N緊張的磨著東西。\n";
                break;
        case 3:
                msg_me = "你接著把那些殘留的大塊兒一點的藥材搗碎。\n";
                msg_out = "$N突然又叮咣叮咣的搗個不停。\n";
                break;
        case 4:
                msg_me = "你細細的將所有的藥材磨成了粉末。\n";
                msg_out = "$N拿著棒杵磨來磨去。\n";
                break;
        case 5:
                msg_me = "你輕輕的合上" + qm->name() +
                         "，默默的運用內力，烘培裡面的藥材。\n";
                msg_out = "$N合上" + qm->name() + "，雙手抱著，不知道在幹什麼。\n";
                break;
        case 6:
                if( query("jing", me)<req["jing"] )
                {
                        write("你覺得精神不濟，看來難以繼續調劑「" +
                              med->name() + "」。\n");
                        return stop_making(me);
                }
                        
        
                if( query("neili", me)<req["neili"] )
                {
                        write("你覺得內力不濟，看來難以繼續調劑「" +
                              med->name() + "」。\n");
                        return stop_making(me);
                }
        
                if( query("jingli", me)<req["jingli"] )
                {
                        write("你覺得精力不濟，看來難以繼續調劑「" +
                              med->name() + "」。\n");
                        return stop_making(me);
                }
        
                me->receive_damage("jing", req["jing"]);
                addn("neili", -req["neili"], me);
                addn("jingli", -req["jingli"], me);

                if( me->add_temp("making/time",-1)>0 )
                {
                        // when time > 0, next busy stage will
                        // still at 6, becuase the step will be
                        // increase by 1 later, so I decrase it
                        // first
                        step--;
                }

                msg_me = random(2) ? "你覺得" + qm->name() + "慢慢的熱了起來，感"
                                     "覺到裡面的藥材似乎已經融化了。\n"
                                   : "你不斷的將內力傳入" + qm->name() + "，發熱"
                                     "使裡面的藥材融化合一。\n";
                msg_out = random(2) ? "$N像老和尚一樣閉目冥神坐在那裡。\n"
                                    : "$N手裡握著" + qm->name() + "沒完沒了的轉來轉去。\n";

                break;
        case 7:
                msg_me = "你運用內力，隔著" + qm->name() + "使裡面的藥材徹底的融合。\n";
                msg_out = "$N眉毛動了動，接著又像老和尚一樣閉目冥神坐在那裡。\n";
                break;
        case 8:
                msg_me = "你長吁了一口氣，慢慢的把手拿開，打開了" + qm->name() + "。\n";
                msg_out = "$N長吁了一口氣，慢慢的把手拿開，打開了" + qm->name() + "。\n";
                break;
        case 9:
                if ((random(me->query_skill("medical", 1) +
                     query("item_prop/medical", qm)) >= req["min_level"]) ||
                    (me->query_skillo("liandan-shu", 1) + query("item_prop/liandan-shu", qm)) >= req["liandan-shu"]+100 )
                {
                        //level = req["liandan-shu"]/300;
                        ob = new(med);
                        obname = ob->name();
                        //set("drug_grade", level, ob);
                        ob->move(qm, 1);
                        if (flag_jiu && 
                                ((!random(8)) || (random(me->query_skillo("liandan-shu", 1) + query("item_prop/liandan-shu", qm)) > 5000) ) && 
                                sscanf(base_name(environment(me)),"/d/dongtian/%*s/liandanfang")) {
                                new(med)->move(qm, 1);
                                message_vision(NOR CYN "煉丹房裡" YEL "金龍" NOR CYN "虛影遊動吞吐，大量靈氣聚集在$N手中的" + qm->name() + NOR CYN "上。\n" , me);
                                tell_object(me, NOR + " (" HIG + "你手裡的" + NOR + qm->name() + NOR + HIG + "一陣劇烈震動，" + obname + NOR + HIG + "的數量＋１。" NOR ")\n");
                                if (flag_jiu>1 && random(2)) {
                                        new(med)->move(qm, 1);
                                        message_vision(NOR CYN "煉丹房裡" YEL "金龍" NOR CYN "虛影遊動吞吐，大量靈氣聚集在$N手中的" + qm->name() + NOR CYN "上。\n" , me);
                                    tell_object(me, NOR + " (" HIG + "你手裡的" + NOR + qm->name() + NOR + HIG + "一陣劇烈震動，" + obname + NOR + HIG + "的數量＋１。" NOR ")\n");
                                        if (random(me->query_skillo("liandan-shu", 1) + query("item_prop/liandan-shu", qm))>7500 && random(me->query_kar())>26 && random(2)) {
                                                new(med)->move(qm, 1);
                                                message_vision(NOR CYN "煉丹房裡" YEL "金龍" NOR CYN "虛影遊動吞吐，大量靈氣聚集在$N手中的" + qm->name() + NOR CYN "上。\n" , me);
                                            tell_object(me, NOR + " (" HIG + "你手裡的" + NOR + qm->name() + NOR + HIG + "一陣劇烈震動，" + obname + NOR + HIG + "的數量＋１。" NOR ")\n");
                                        }
                                        if (random(me->query_skillo("liandan-shu", 1) + query("item_prop/liandan-shu", qm))>10000 && random(2)) {
                                                new(med)->move(qm, 1);
                                                message_vision(NOR CYN "煉丹房裡" YEL "金龍" NOR CYN "虛影遊動吞吐，大量靈氣聚集在$N手中的" + qm->name() + NOR CYN "上。\n" , me);
                                            tell_object(me, NOR + " (" HIG + "你手裡的" + NOR + qm->name() + NOR + HIG + "一陣劇烈震動，" + obname + NOR + HIG + "的數量＋１。" NOR ")\n");
                                        }
                                }
                        }
                        if (random(4) && query_temp("tiandilu/type", me)) {
                                                        switch(query_temp("tiandilu/type", me))
                                                {
                                                        case 1:
                                                                ob2 = new("/clone/medicine/yuqing");
                                                                break;
                                                        case 2:
                                                                ob2 = new("/clone/gift/puti-zi");
                                                                break;
                                                        case 3:
                                                                ob2 = new("/clone/gift/jiuzhuan");
                                                                break;
                                                }
                                                        delete_temp("tiandilu/type", me);
                                        message_vision(NOR HIC "$N手中的" + qm->name() + NOR HIC "裡額外凝聚出了" + ob2->name() + NOR HIC "。\n" NOR , me);
                                        ob2->move(qm, 1);
                                        if (!random(200000)) {
                                                set_temp("tiandilu/bomb", qm, me);
                                        }
                        }
                        msg_me = HIM "你把「" + obname + HIM "」成功的制好了！\n" NOR;
                        msg_out = HIM "$N" HIM "嘴角露出一絲微笑。\n" NOR;
                        me->improve_skill("liandan-shu", me->query_int()*100+100); 
                }else if( !query("special_skill/lucky", me) || random(2) == 0 )
                {
                        msg_me = HIG "真令人沮喪！居然失敗了，真是可惜了。\n" NOR;
                        msg_out = HIG "$N" HIG "一臉沮喪，不"
                                  "知道發生了什麼倒黴事。\n" NOR;
                }else
                {
                        ob = new(med);
                        ob->move(qm, 1);
                        msg_me = HIM "你感覺似乎有什麼地方沒有做對，然而你的運氣實在太好了！\n你把「" + ob->name() + HIM "」成功的制好了！\n" NOR;
                        msg_out = HIM "$N" HIM "嘴角露出一絲微笑。\n" NOR;
                        me->improve_skill("liandan-shu", me->query_int()*10+10); 
                }
                break;
        }

        msg_out = replace_string(msg_out, "$N", me->name());
        message("vision", msg_me, me);
        message("vision", msg_out, environment(me), ({ me }));
        step++;
        if (step >= 10)
                // end of making
                return stop_making(me);

        set_temp("pending/making", step, me);
        return 1;
}

int halt_make(object me)
{
        message_vision("$N把手中的研缽一翻個，東西"
                       "全都倒了出來。\n", me);
        stop_making(me);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : make [<藥品>] [?]

這個指令可以讓你煉製某樣藥品，如果沒有指明藥品則會列出當前
你會煉製的藥品。如果在指明的藥品後面添加一個"?" 則會列出煉
制這種藥品需要的材料。

HELP );
    return 1;
}
