#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string str) {
    mapping question;
    string code;
    object env;
    int ret;

    env = environment(me);
    if(env ) {
        ret = "/adm/daemons/fubend"->enter_fuben_private(me, base_name(env));
    }
    if(ret ) {
        tell_object(me, "你進入了私有副本。\n");
    } else {
        tell_object(me, "當前位置無法創建私有副本。\n");
    }
    return 1;
    if(str && sscanf(str, "answer %s", str) == 1 && sizeof(str) > 0 )
    {
        if(str == "giveup" )
        {
            if(query("balance", me) < 5000000 )
                return notify_fail("你的存款不足500兩黃金，無法取消本次驗證碼。\n");

            addn("balance", -5000000, me);
            delete_temp("fuben_captcha_code", me);

            write("本次驗證碼取消成功。\n");
            return 1;
        }
        if(str == query_temp("fuben_captcha_code", me) )
        {
            delete_temp("fuben_captcha_code", me);

            env = environment(me);
            if(env ) {
                ret = "/adm/daemons/fubend"->enter_fuben_private(me, base_name(env));
            }
            if(ret ) {
                tell_object(me, "你進入了私有副本。\n");
            } else {
                tell_object(me, "當前位置無法創建私有副本。\n");
            }
            return 1;
        }
        else
            return notify_fail("驗證碼輸入錯誤。\n");
    }
    if(query_temp("fuben_captcha_code", me) )
    {
        write(HIY"\n請輸入「fboss answer 驗證碼」以建立私有副本空間挑戰boss。\n"NOR);
        return 1;
    }

    question = X_PointD->get_question();
    code = question["answer"];
    set_temp("fuben_captcha_code", code, me);
    write("\n驗證碼為：\n\n"NOR);
    write(question["question"]);
    write("\n輸入「fboss answer 驗證碼」以建立私有副本空間挑戰boss。\n"NOR);
    return 1;

}
