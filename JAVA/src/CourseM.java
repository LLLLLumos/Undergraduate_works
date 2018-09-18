package LOOHCS;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class CourseM {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame myframe=new CFrame();
	      myframe.show();
	}

}

class CFrame extends JFrame implements ActionListener{
    private Connection con=null;
    private Statement stmt=null;
    private ResultSet  rs=null;
    private JLabel conditionlabel
        =new JLabel ("  ",SwingConstants.CENTER);
    private JLabel cnolabel=new JLabel("�γ̺�:",SwingConstants.RIGHT);
    private JTextField cno=new JTextField(3);
    private JLabel cnamelabel=new JLabel("�γ���:",SwingConstants.RIGHT);
    private JTextField cname=new JTextField(12);
    private JLabel creditlabel=new JLabel("ѧ��:",SwingConstants.RIGHT);
    private JTextField credit=new JTextField(2);
    private JLabel titlelabel=new JLabel("�γ̺�      �γ���                        ѧ�� ",SwingConstants.RIGHT);
    private JButton commit=new JButton("��ѯ");
    private JButton insert=new JButton("����");
    private JButton change=new JButton("�޸�");
    private JButton delete=new JButton("ɾ��");
    private JLabel resultarea=new JLabel("  ");  
    private JTextArea resarea=new JTextArea(9,20); 
    private  String command=null;
    private  String sex="";
    @SuppressWarnings("deprecation")
	public CFrame(){
        setTitle("�γ���Ϣ����");
        setSize(380,320); 
        addWindowListener(new WindowAdapter(){
           public void windowClosing(WindowEvent e)
               { dispose(); }
        });
        getContentPane().setLayout(new GridBagLayout());
           //ʹ��GridBagLayout���ֱ���Swing���
        GridBagConstraints gbc=new GridBagConstraints();
        gbc.fill=GridBagConstraints.NONE;
        gbc.anchor=GridBagConstraints.CENTER; 
        gbc.weightx=100;
        gbc.weighty=100;
        add(conditionlabel,gbc,0,0,5,1);
        JScrollPane scrollpane=new JScrollPane(resarea);
        resarea.setEditable(false);
        resarea.setLineWrap(true);//�Զ�����
        gbc.anchor=GridBagConstraints.EAST; 
        add(cnolabel,gbc,0,1,1,1); 
        add(cnamelabel,gbc,2,1,1,1); 
        add(creditlabel,gbc,4,1,1,1);
        gbc.anchor=GridBagConstraints.NORTHWEST;
        add(scrollpane,gbc,1,5,4,4);
        add(titlelabel,gbc,1,4,4,1);
        add(cno,gbc,1,1,1,1);
        add(cname,gbc,3,1,1,1);
        add(credit,gbc,5,1,1,1);
        add(resultarea,gbc,3,3,3,1);
        add(commit,gbc,4,5,2,1);
        add(insert,gbc,4,6,2,1);
        add(change,gbc,4,7,2,1); 
        add(delete,gbc,4,8,2,1);
        commit.addActionListener(this);
        insert.addActionListener(this);
        change.addActionListener(this);
        delete.addActionListener(this);
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
    	 String cnamevalue=cname.getText().trim();
    	 String creditvalue=credit.getText().trim();
    	 if(evt.getSource()==commit){
    		 String scno=" LIKE '%"+cnovalue+"%'";//֧��ģ������
    		 String scname=" LIKE '%"+cnamevalue+"%'";//֧��ģ������
    		 String scredit=" LIKE '%"+creditvalue+"%'";//֧��ģ������
    		 command="SELECT * FROM course WHERE cno"+scno+" AND cname"+scname+" AND credit"+scredit+" ORDER BY cno DESC";
    		try{
                 rs=stmt.executeQuery(command);
                 if(rs.next()) 
                 { 
                       resultarea.setText("��ѯ�ɹ�");
                       resarea.setText("");
                       do{
                           String recno=rs.getString("cno").trim();
                           String recname=rs.getString("cname").trim();
                           String recredit=rs.getString("credit").trim();
                           resarea.append(" ");
                           resarea.append(recno);//����
                           resarea.append("               ");
                           resarea.append(recname);//����
                           resarea.append("\t");
                           resarea.append(recredit+"  \n"); 
                       }while(rs.next());
                 } 
                   else{
                	   resultarea.setText("�޷��������ļ�¼");
                	   resarea.setText("");
                   } 
                 sex="";
               }
            catch(Exception ex) {
               resultarea.setText(ex.getMessage());
           }
    	 }
    	 else if(evt.getSource()==insert){
    		 if(!cnovalue.equals("")){
    			 command="SELECT * FROM course WHERE cno="+cnovalue;
                 try{
                    rs=stmt.executeQuery(command);
                     if(rs.next()) 
                        resultarea.setText("�ظ����Ƿ���£�");
                      else{
                         command="insert into course values("+cnovalue+",'"+cnamevalue+"',"+creditvalue+")"; 
                            try{
                               stmt.executeUpdate(command);
                               resultarea.setText("�ɹ�����һ���γ���Ϣ");
                                }catch(Exception ex) {
                                      resultarea.setText("����ʧ��"+ex.getMessage());}
                           } 
                     }catch(Exception ex) {
                            resultarea.setText(ex.getMessage());
                        } 
    		 }
    		 else
    			 resultarea.setText("������γ���Ϣ");
         } 
    	 else if(evt.getSource()==delete){
    		 if(!cnovalue.equals("")){
    			 command="delete from course where cno="+cnovalue;
    		 try{
           	     stmt.executeUpdate(command);
                 resultarea.setText("ɾ���ɹ�");
               }
             catch(Exception ex) {
               resultarea.setText(ex.getMessage());
              }
    		 }
    		 else if(!cnamevalue.equals("")){
    			 command="delete from course where cname='"+cnamevalue+"'";
    			 try{
               	     stmt.executeUpdate(command);
                     resultarea.setText("ɾ���ɹ�");
                   }
                 catch(Exception ex) {
                   resultarea.setText(ex.getMessage());
                  }
    		 }
    		 else
    			 resultarea.setText("ɾ��ʧ��");
    		 
    		 
    	 }
    	 else if(evt.getSource()==change){
    		if(!cnamevalue.equals("")){
    			command="update course set cname='"+cnamevalue+" where cno="+cnovalue;
       		 try{
              	     stmt.executeUpdate(command);
                    resultarea.setText("�ɹ�����һ���γ���Ϣ");
                  }
                catch(Exception ex) {
                  resultarea.setText(ex.getMessage());
                 }
    		}
    		if(!creditvalue.equals("")){
    			command="update course set credit="+creditvalue+" where cno="+cnovalue;
       		 try{
              	     stmt.executeUpdate(command);
                    resultarea.setText("�ɹ�����һ���γ���Ϣ");
                  }
                catch(Exception ex) {
                  resultarea.setText(ex.getMessage());
                 }
    		}
    		
    	 }
    	 
    }
}