package LOOHCS;
import java.sql.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

import java.util.*;

public class manager {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame myframe=new MFrame();
	      myframe.show();
	}

}

class MFrame extends JFrame implements ActionListener{
    private Connection con=null;
    private Statement stmt=null;
    private ResultSet  rs=null;
    private String command="";
    private JLabel conditionlabel
        =new JLabel ("  ",SwingConstants.CENTER);
    private JLabel namelabel=new JLabel("登录名:",SwingConstants.RIGHT);
    private JTextField name=new JTextField(8);
    private JLabel pswlabel=new JLabel("密   码:",SwingConstants.RIGHT);
    private JLabel TIPlabel=new JLabel(" ",SwingConstants.RIGHT);
    private JPasswordField psw=new JPasswordField(8);
    private JButton commit=new JButton("登录");
    private JButton out=new JButton("退出");
    private JButton stu=new JButton("学生信息管理");
    private JButton cou=new JButton("课程信息管理");
    private JButton gra=new JButton("成绩管理");
    @SuppressWarnings("deprecation")
	public MFrame(){
        setTitle("管理员主页");
        setSize(350,200); 
        addWindowListener(new WindowAdapter(){
           public void windowClosing(WindowEvent e)
               { System.exit(0); }
        });
        getContentPane().setLayout(new GridBagLayout());
           //使用GridBagLayout布局编排Swing组件
        GridBagConstraints gbc=new GridBagConstraints();
        gbc.fill=GridBagConstraints.NONE;
        gbc.anchor=GridBagConstraints.CENTER; 
        gbc.weightx=100;
        gbc.weighty=100;
        add(conditionlabel,gbc,0,0,7,1);
        add(TIPlabel,gbc,2,3,7,1);
        gbc.anchor=GridBagConstraints.NORTHEAST; 
        add(namelabel,gbc,3,1,1,1); 
        add(pswlabel,gbc,3,2,1,1); 
        add(commit,gbc,5,1,1,1);
        gbc.anchor=GridBagConstraints.NORTHWEST;
        add(commit,gbc,5,1,3,1);
        add(out,gbc,5,2,3,1);
        add(name,gbc,4,1,1,1);
        add(psw,gbc,4,2,1,1);
        add(stu,gbc,3,5,1,1);stu.setVisible(false);
        add(cou,gbc,4,5,1,1); cou.setVisible(false);
        add(gra,gbc,5,5,1,1);gra.setVisible(false);
        commit.addActionListener(this);
        out.addActionListener(this);
        stu.addActionListener(this);
        cou.addActionListener(this);
        gra.addActionListener(this);
        try{
	           Class.forName("com.mysql.jdbc.Driver");
	           con=DriverManager.getConnection("jdbc:mysql://localhost:3306/school?autoReconnect=true&useUnicode=true&characterEncoding=UTF-8","root","1216");
	           stmt=con.createStatement();
	        } catch(Exception ex) {
	        	TIPlabel.setText(ex.getMessage()+"\n"); 
	           return;
	        }
      }
      public void add(Component c,GridBagConstraints gbc,int x,int y,
         int w, int h) {
         gbc.gridx=x;
         gbc.gridy=y;
         gbc.gridwidth=w;
         gbc.gridheight=h;
         getContentPane().add(c,gbc);
      }
      public void actionPerformed(ActionEvent evt) {
    	 if(evt.getSource()==commit){
    		 String mname=name.getText().trim();
        	 String spsw=String.valueOf(psw.getPassword());
    		 command="SELECT psw FROM manager WHERE mname='"+mname+"'";
     		try{
                  rs=stmt.executeQuery(command);
                  if(rs.next())
                  {
                	  String tpsw=rs.getString("psw").trim();
                	  if(spsw.equals(tpsw)) 
                      {
          		         TIPlabel.setText("登录成功，请选择操作");
                          stu.setVisible(true);
                          cou.setVisible(true);
                          gra.setVisible(true);
                      }
                      else{
                    	  TIPlabel.setText("用户名或密码错误");
                    	  stu.setVisible(false);
                          cou.setVisible(false);
                          gra.setVisible(false);
                      }
                  }
                	  else {
                		  stu.setVisible(false);
                          cou.setVisible(false);
                          gra.setVisible(false);
                          TIPlabel.setText("用户名错误");
                	  }
                  
     		}catch(Exception ex) {
     			TIPlabel.setText(ex.getMessage());
            }
         } 
    	 else if(evt.getSource()==out){
    		 stu.setVisible(false);
             cou.setVisible(false);
             gra.setVisible(false);
             TIPlabel.setText("");
             name.setText("");
             psw.setText("");
         }
     	 else if(evt.getSource()==stu){
     		 JFrame myframe=new SFrame();
   	         myframe.show();
         } 
    	 else if(evt.getSource()==cou){
    		 JFrame myframe=new CFrame();
   	         myframe.show();
    	 }
    	 else if(evt.getSource()==gra){
    		 JFrame myframe=new GFrame();
   	         myframe.show();
    	 }
    	 
    }
}
