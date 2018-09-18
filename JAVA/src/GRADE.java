package LOOHCS;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class GRADE {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame myframe=new GFrame();
	      myframe.show();
	}

}

class GFrame extends JFrame implements ActionListener{
    private Connection con=null;
    private Statement stmt=null;
    private ResultSet  rs=null;
    private JLabel conditionlabel
        =new JLabel ("  ",SwingConstants.CENTER);
    private JLabel cnolabel=new JLabel("课程号",SwingConstants.RIGHT);
    private JTextField cno=new JTextField(11);
    private JLabel snolabel=new JLabel("学号",SwingConstants.RIGHT);
    private JTextField sno=new JTextField(11);
    private JLabel gradelabel=new JLabel("成绩",SwingConstants.RIGHT);
    private JTextField grade=new JTextField(6);
    private JLabel titlelabel=new JLabel("        课程号                 学号                   成绩",SwingConstants.RIGHT);
    private JButton commit=new JButton("查询");
    private JButton insert=new JButton("插入");
    private JButton change=new JButton("修改");
    private JLabel resultarea=new JLabel(" ",SwingConstants.RIGHT);
    private JTextArea resarea=new JTextArea(10,40); 
    private  String command=null;
    @SuppressWarnings("deprecation")
	public GFrame(){
        setTitle("成绩管理");
        setSize(500,350); 
        addWindowListener(new WindowAdapter(){
           public void windowClosing(WindowEvent e)
               { dispose(); }
        });
        getContentPane().setLayout(new GridBagLayout());
           //使用GridBagLayout布局编排Swing组件
        GridBagConstraints gbc=new GridBagConstraints();
        gbc.fill=GridBagConstraints.NONE;
        gbc.anchor=GridBagConstraints.CENTER; 
        gbc.weightx=100;
        gbc.weighty=100;
        add(conditionlabel,gbc,1,0,7,1);
        JScrollPane scrollpane=new JScrollPane(resarea);
        resarea.setEditable(false);
        resarea.setLineWrap(true);
        gbc.anchor=GridBagConstraints.EAST; 
        add(cnolabel,gbc,2,1,1,1); 
        add(snolabel,gbc,4,1,1,1); 
        add(gradelabel,gbc,6,1,1,1);
        gbc.anchor=GridBagConstraints.WEST;
        add(cno,gbc,3,1,1,1);
        add(sno,gbc,5,1,1,1);
        add(grade,gbc,7,1,1,1);
        add(titlelabel,gbc,2,3,4,1);
        gbc.anchor=GridBagConstraints.EAST; 
        add(commit,gbc,5,2,1,1);
        gbc.anchor=GridBagConstraints.CENTER; 
        add(insert,gbc,6,2,1,1);
        gbc.anchor=GridBagConstraints.WEST; 
        add(change,gbc,7,2,1,1); 
        gbc.anchor=GridBagConstraints.NORTH; 
        add(scrollpane,gbc,1,5,7,3);
        add(resultarea,gbc,2,2,4,3);
        commit.addActionListener(this);
        insert.addActionListener(this);
        change.addActionListener(this);
        commit.setNextFocusableComponent(cno); 
        try{
           Class.forName("com.mysql.jdbc.Driver");
           con=DriverManager.getConnection("jdbc:mysql://localhost:3306/school?autoReconnect=true&useUnicode=true&characterEncoding=UTF-8","root","1216");
           stmt=con.createStatement();
        } catch(Exception ex) {
           resultarea.setText(ex.getMessage()+"\n"); 
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
    	 String cnovalue=cno.getText().trim();
    	 String snovalue=sno.getText().trim();
    	 String gradevalue=grade.getText().trim();
    	 if(evt.getSource()==commit){
    		 if(!snovalue.equals("")&!cnovalue.equals("")){
    		 command="SELECT grade FROM sc WHERE cno="+cnovalue+" AND sno="+snovalue;
    		 try{
                 rs=stmt.executeQuery(command);
                 if(rs.next()) 
                 { 
                       resultarea.setText("查询成功");
                       String regrade=rs.getString("grade").trim();
                       grade.setText(regrade);
                 } 
                   else{
                	   grade.setText("");
                	   resultarea.setText("无此记录");
                   } 
               }
            catch(Exception ex) {
               resultarea.setText(ex.getMessage());
           }
    		 }
    		 else resultarea.setText("请输入要查询成绩的课程号和学号");
    	 }
    	 else if(evt.getSource()==insert){
    		 if(!snovalue.equals("")&!cnovalue.equals("")&!gradevalue.equals("")){
    		 command="SELECT * FROM course WHERE cno="+cnovalue;
    		 try{
                 rs=stmt.executeQuery(command);
                 if(rs.next()) 
                 { 
                	 command="SELECT * FROM student WHERE sno="+snovalue;
                	 try{
                         rs=stmt.executeQuery(command);
                         if(rs.next()) 
                         {   command="SELECT grade FROM sc WHERE cno="+cnovalue+" AND sno="+snovalue;
                		 try{
                             rs=stmt.executeQuery(command);
                             if(rs.next()) 
                             {  
                                   resultarea.setText("重复！请选择是否更新");
                                   String regrade=rs.getString("grade").trim();
                                   grade.setText(regrade);
                             } 
                               else{
                            	   command="insert into sc values("+cnovalue+","+snovalue+","+gradevalue+")"; 
                          		 try{
                                 	     stmt.executeUpdate(command);
                                       resultarea.setText("成功插入一条成绩记录");
                                     }
                                   catch(Exception ex) {
                                     resultarea.setText(ex.getMessage());
                                    }
                               } 
                           }
                        catch(Exception ex) {
                           resultarea.setText(ex.getMessage());
                       }
                        	 
                         } 
                           else{
                        	   grade.setText("");
                        	   resultarea.setText("请输入正确的学号");
                           } 
                       }catch(Exception ex) {
                           resultarea.setText(ex.getMessage());
                       }
                 } 
                   else{
                	   grade.setText("");
                	   resultarea.setText("请输入正确的课程号");
                   } 
               }
            catch(Exception ex) {
               resultarea.setText(ex.getMessage());
           }
    	 }
		 else resultarea.setText("请输入要插入成绩的信息");
    	 }
    	 else if(evt.getSource()==change){
    		 if(!snovalue.equals("")&!cnovalue.equals("")&!gradevalue.equals("")){
    		 command="update sc set grade='"+gradevalue+ "' where cno="+cnovalue+" and sno="+snovalue;
    		 try{
           	     stmt.executeUpdate(command);
                 resultarea.setText("成功更新一条成绩记录");
               }
             catch(Exception ex) {
               resultarea.setText(ex.getMessage()+"\n"+command+"\n");
              }
    		 }
    		 else resultarea.setText("请输入要更新成绩的信息");
    	 }
    	 try{
             command="SELECT * FROM sc ORDER BY cno DESC"; 
             rs=stmt.executeQuery(command);
             resarea.setText("");
             if(rs.next()) 
             { 
               do{
                   String recno=rs.getString("cno").trim();
                   String resno=rs.getString("sno").trim();
                   String regrade=rs.getString("grade").trim();
                   resarea.append(recno);//对齐
                   resarea.append("\t");
                   resarea.append(resno);//对齐
                   resarea.append("\t");
                   resarea.append(regrade+"              \n"); 
               }while(rs.next());
           }
       } catch(Exception ex) {
           resarea.append(ex.getMessage()+"\n"+command+"\n");
       }  
     
    }
}