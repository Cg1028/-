package main

import (
	"fmt"
	"math/rand"
	"net/http"
	"strconv"
	"time"
)

var Userstore map[string]*User

type User struct {
	ID            string
	Name          string
	password      string
	gender        string
	age           string
	selfintroduce string
	cookie        http.Cookie
}

func Mainpage(w http.ResponseWriter, r *http.Request) {
	for id, ck := range Userstore {
		cookie, err := r.Cookie(id)
		if err == nil && cookie.Value == ck.cookie.Value {
			fmt.Fprintf(w, "序列%s：,欢迎你。", id)
		}else{
			return
		}
	}
	w.Write([]byte("请先登录！"))

}

func Login(w http.ResponseWriter, r *http.Request) {
	ID := r.FormValue("您的序列")
	password := r.FormValue("您的密令")
	if hereID, judge := Userstore[ID]; judge { /*判断用户是否存在*/
		if hereID.password == password {
			rand.Seed(time.Now().UnixNano())
			value := strconv.Itoa(rand.Intn(10000))
			expire := time.Now().AddDate(0, 0, 1)
			cookie := &http.Cookie{
				Name:    ID,
				Value:   value,
				Expires: expire,
			}
			http.SetCookie(w, cookie)
			hereID.cookie = *cookie
			w.Write([]byte("序列%s:  您已成功登录！"))
		} else {
			w.Write([]byte("密令错误，登陆失败"))
		}
	} else {
		w.Write([]byte("你不在序列内！"))
	}
}

func Modify(w http.ResponseWriter, r *http.Request) {
	for a, b := range Userstore {
		cookie, err := r.Cookie(a)
		if err == nil && cookie.Value == b.cookie.Value {

			if err != nil {
				return
			}
			ID := r.FormValue("序列")
			password := r.FormValue("密令")
			Name := r.FormValue("代号")
			age := r.FormValue("年龄")
			gender := r.FormValue("性别")
			selfintroduce := r.FormValue("自我介绍")
			modifyuser := Userstore[ID]
			if ID != "" {

				if password != "" {
					modifyuser.password = password
				}
				if Name != "" {
					modifyuser.Name = Name
				}
				if age != "" {
					modifyuser.age = age
				}
				if gender != "" {
					modifyuser.gender = gender
				}
				if selfintroduce != "" {
					modifyuser.selfintroduce = selfintroduce
				}
				_, err := w.Write([]byte("修改完毕"))
				if err != nil {
					return
				}
			}
		}
	}
}

func Register(w http.ResponseWriter, r *http.Request) {
	var use User
	user := &use
	ID := r.FormValue("您要注册的序列")
	password := r.FormValue("您要注册的密令")
	if ID != "" && password != "" {
		user.ID = ID
		user.password = password
		Userstore[ID] = user
		w.Write([]byte("您已注册成功,请跳转至登录页面"))
	} else {
		w.Write([]byte("注册失败，请重新确认信息！"))
	}
}

func main() {
	mymux := http.NewServeMux()
	server := &http.Server{
		Addr:    ":7890",
		Handler: mymux,
	}
	mymux.HandleFunc("/mainpage", Mainpage)
	mymux.HandleFunc("/regist", Register)
	mymux.HandleFunc("/login", Login)
	mymux.HandleFunc("/mainpage/modifypassword", Modify)
	server.ListenAndServe()

}
