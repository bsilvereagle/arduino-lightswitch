from flask import Flask
import controls

application = Flask(__name__)

@application.route("/on")
def turnOn():
        test.on()
        return "<html><body><p style='font-size:32pt'>Light is On</p><a href='/off'/><p style='width:100%;height:200px;background:red'>Off</p></a></body></html>"

@application.route("/off")
def turnOff():
	test.off()
	return "<html><body><p style='font-size:32pt'>Light is Off</p><a href='/on'/><p style='width:100%;height:200px;background:green'>On</p></a></body></html>"

if __name__ == '__main__':
	application.debug=True
	application.run(host='0.0.0.0')
